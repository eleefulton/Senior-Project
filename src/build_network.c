#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "runner.h"

int min(int a, int b)
{
  if(a < b) return a;
  else return b;
}

/*
  initialize the input layer with the input value tags
  these tags should correspond with the 50-words
*/
int initialize_input_layer(char *input_value_tags[], Node *input_layer, int n)
{
  for(int i = 0; i < n; i++)                                                   // initalize input layer nodes tags
  {
    input_layer[i].tag = input_value_tags[i];
    input_layer[i].bias = 0;                                                   // input layer does not need a bias
  }
  return n;                                                                    // return n
}

/*
  initalize the literal layer with the literals as tags
  scan the dnf file for each unique literal
  return the number of literals found
*/
int initialize_literal_layer(char *file_name, Node *literal_layer)
{
  FILE *dnf_file = fopen(file_name, "r");                                      // open dnf file
  if(dnf_file == NULL)                                                         // check dnf file opened propperly
  {
    printf("failed to open dnf_file\n");
    return -1;
  }

  char *literals[MAX_LITERALS];                                                // array to hold found literals as strings
  for(int i = 0; i < MAX_LITERALS; i++)                                        // initalize found literals
  {
    literals[i] = malloc(sizeof(char)*MAX_LENGTH);                             // allocate space for literal string
    for(int j = 0; j < MAX_LENGTH; j++)                                        // initalize all spots of literal string to null char
    {
      literals[i][j] = '\0';
    }
  }
  
  char literal[MAX_LENGTH];                                                    // string to hold parsed literal
  literal[0] = '\0';                                                           // initalize beginning of literal to null
  int index = 0;                                                               // index of location in literal string
  int num_literals = 0;
  char c = fgetc(dnf_file);                                                    // read first char in file
  while(c != EOF)                                                       // loop until end of dnf file
  {
    if(c == '|' || c == '&')                                      // if c == | or & it's the end of literal
    {
      if(c == '|')                                                             // if c == | move index back one to remove category tag
        index--;
      literal[index] = '\0';                                                   // terminate literal string with null char
      index = 0;                                                               // reset index to zero
      if(!in_string_list(literal, literals, num_literals))                     // check if this literal is already in the array of found literals
      {
        strncpy(literals[num_literals], literal, strlen(literal));             // if it's not alreay found copy literal string to array
        num_literals++;                                                        // increase number of literals found
      }
    }
    else if(c != ' ')                                                          // otherwise if c != ' '
    {
      literal[index] = c;                                                      // add char to string
      index++;                                                                 // increment index
    }
    c = fgetc(dnf_file);                                                       // get next char
  }
  literal[index-2] = '\0';
  strncpy(literals[num_literals], literal, strlen(literal));
  num_literals++;
  fclose(dnf_file);                                                            // close dnf file

  for(int i = 0; i < num_literals; i++)                                        // move literals from string array to Nodes tags
  {
    literal_layer[i].tag = literals[i];
  }  
  return num_literals;                                                         // return number of literals
}

/*
  initalize the conjunctive layer with conjuncts as tags
  last char of each conjunct represent the output it produces
  scan the dnf file for all conjuncts
  return number of conjuncts found
*/
int initialize_conjunctive_layer(char * file_name, Node *conjunctive_layer)
{
  FILE *dnf_file = fopen(file_name, "r");                                      // open dnf file
  if(dnf_file == NULL)                                                         // check dnf file opened propperly
  {
    printf("failed to open dnf_file\n");
    return -1;
  }

  char *conjuncts[MAX_CONJUNCTS];                                              // array to hold found conjuncts as strings
  for(int i = 0; i < MAX_CONJUNCTS; i++)                                       // initalize found conjuncts
  {
    conjuncts[i] = malloc(sizeof(char)*MAX_LENGTH*MAX_CONJUNCTS);              // allocate space for conjunct string
    for(int j = 0; j < MAX_LENGTH*MAX_CONJUNCTS; j++)                          // initalize all spots of conjunct string to null char
    {
      conjuncts[i][j] = '\0';
    }
  }
  
  char conjunct[MAX_LENGTH * MAX_LENGTH];                                       // string to hold parsed literal
  conjunct[0] = '\0';                                                           // initalize beginning of literal to null
  int index = 0;                                                               // index of location in literal string
  int num_conjuncts = 0;
  char c = fgetc(dnf_file);                                                    // read first char in file
  while(c != EOF)                                                       // loop until end of dnf file
  {
    if(c == '|')                                      // if c == | or & it's the end of literal
    {
      conjunct[index] = '\0';                                                   // terminate literal string with null char
      index = 0;                                                               // reset index to zero
      if(!in_string_list(conjunct, conjuncts, num_conjuncts))                  // check if this literal is already in the array of found literals
      {
        strncpy(conjuncts[num_conjuncts], conjunct, strlen(conjunct));             // if it's not alreay found copy literal string to array
        num_conjuncts++;                                                        // increase number of literals found
      }
    }
    else if(c != ' ')                                                          // otherwise if c != ' '
    {
      conjunct[index] = c;                                                      // add char to string
      index++;                                                                 // increment index
    }
    c = fgetc(dnf_file);                                                       // get next char
  }
  conjunct[index-1] = '\0';
  strncpy(conjuncts[num_conjuncts], conjunct, strlen(conjunct));
  num_conjuncts++;
  fclose(dnf_file);                                                            // close dnf file

  for(int i = 0; i < num_conjuncts; i++)                                       // copy conjuncts from string array to Nodes tags
  {
    conjunctive_layer[i].tag = conjuncts[i];
  }  
  return num_conjuncts;                                                        // return number of conjuncts
}

/*
  initialize the output layer with categories as tags
*/
int initialize_output_layer(char *categories[], Node *output_layer, int n)
{
  for(int i = 0; i < n; i++)
  {
    output_layer[i].tag = categories[i];
  }
  return n;
}

/*
  set weights and biases based on nnidt criteria
  if(value > attribute) bias = -alpha * value and weight = alpha
  if(value <= attribute) bias = alpha * value and weight = -alpha
  everything all remaining weights to +/- beta with equal probability
*/
void set_wb_input_to_literal(Node *input_layer, int num_input, Node *literal_layer, int num_literals)
{
  srand(time(NULL));
  for(int i = 0; i < num_input; i++)                                           // loop through all inputs
  {
    for(int j = 0; j < num_literals; j++)                                      // loop through all literals
    {
      if((strlen(literal_layer[j].tag) >= strlen(input_layer[i].tag)) &&       // first check if literal is longer than input
            strncmp(literal_layer[j].tag, input_layer[i].tag,                  // then check if the input is in the literal
            strlen(input_layer[i].tag)) == 0)
      {
        int k = strlen(literal_layer[j].tag) - 2;                              // mark where the equality is
        if(literal_layer[j].tag[k] == '>')                                     // if(attribute > value)
        {
          literal_layer[j].bias = (literal_layer[j].tag[k+1] - 48) * (0-ALPHA);
          input_layer[i].weights[j] = ALPHA;
        }
        else if(literal_layer[j].tag[k] == '=')                                // if(attribute <= value)
        {
          literal_layer[j].bias = (literal_layer[j].tag[k+1] - 48) * ALPHA;
          input_layer[i].weights[j] = 0-ALPHA;
        }
      }
      else                                                                     // set any other weight to +/- BETA
      {
        int random = rand() % 10;                                              // use an equal probablility for +/-      
        input_layer[i].weights[j] = random <= 4 ? BETA : 0 - BETA;
      }
    }
    DoProgress("setting weights from input to literal: ", i+1, num_input);
  }
  printf("\n");
}

/*
  set all weights from literal to conjunct to 5 if literal is in conjunct
  set all biases for conjunt nodes to (-ALPHA * (2n-1))/2 where n is the  number
  of literals that connect to that conjunct
*/
void set_wb_literal_to_conjunctive(Node *literal_layer, int num_literals, Node *conjunctive_layer, int num_conjuncts)
{
  srand(time(NULL));
  for(int i = 0; i < num_literals; i++)                                        // for all nodes in literal layer
  {
    for(int j = 0; j < num_conjuncts; j++)                                     // for all weights from this node to all nodes in conjunctive layer
    {
      float connections = 1;                                                   // count how many literals this conjunct should connect to
      for(int k = 0; k <strlen(conjunctive_layer[j].tag); k++)
      {
        if(conjunctive_layer[j].tag[k] == '&')
          connections++;
      }
      conjunctive_layer[j].bias = (float)(((0-ALPHA)*(2*connections-1))/2);    // set bias for this conjunct
      if(strlen(literal_layer[i].tag) < strlen(conjunctive_layer[j].tag) &&    // if literal is in this conjunct
         strstr(conjunctive_layer[j].tag, literal_layer[i].tag) != NULL)
      {
        literal_layer[i].weights[j] = ALPHA;                                   // set weight to ALPHA
      }
      else                                                                     // otherwise set to +/- BETA
      {
        int random = rand() % 10;
        literal_layer[i].weights[j] = random <= 4 ? BETA : 0 - BETA;
      }
    }
    DoProgress("setting weights from literal to conjunctive: ", i+1, num_literals);
  }
  printf("\n");
}

/*
  set weights from conjunctive layer node to output layer node (if
  that conjunct produces that output) to ALPHA
  set biases of output nodes to -ALPHA * 0.5
*/
void set_wb_conjunctive_to_output(Node *conjunctive_layer, int num_conjuncts, Node *output_layer, int num_categories)
{
  srand(time(NULL));
  for(int i = 0; i < num_conjuncts; i++)                                       // for all nodes in conjunctive layer
  {
    for(int j = 0; j < num_categories; j++)                                    // set all weights from this conjunct node to all output nodes
    {
      if(conjunctive_layer[i].tag[strlen(conjunctive_layer[i].tag)-1]          // if this conjunct leads to this output
           == output_layer[j].tag[0])
      {
        conjunctive_layer[i].weights[j] = ALPHA;                                // set weight to ALPHA
      }
      else                                                                     // otherwise set weight to +/- BETA
      {
        int random = rand() % 10;
        conjunctive_layer[i].weights[j] = random <= 4 ? BETA : 0 - BETA;
      }
      output_layer[j].bias = (float)(0-ALPHA)/(float)2;                        // set bias for this output node to -ALPHA / 2
    }
    DoProgress("setting weights from conjunctive to output: ", i+1, num_conjuncts);
  }
  printf("\n");
}
