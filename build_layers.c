#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "build_layers.h"
#include "tfidf.h"

#define MAX_LITERALS 500
#define MAX_CONJUNCTS 500

int in_layer_list(char* string, char *list[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(strncmp(string, list[i], MAX_LENGTH) == 0)
      return 1;
  }
  return 0;
}

void build_literal_layer(char *file_name)
{
  FILE *dnf_file = fopen(file_name, "r");                                      // open dnf file
  if(dnf_file == NULL)                                                         // check dnf file opened propperly
  {
    printf("failed to open dnf_file\n");
    return;
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
  int num_literals = 0;                                                        // keep track of number of unique literals
  char c = fgetc(dnf_file);                                                    // read first char in file
  while(!feof(dnf_file))                                                       // loop until end of dnf file
  {
    if(c == '|' || c == '&')                                                   // if c == | or & it's the end of literal
    {
      literal[index] = '\0';                                                   // terminate literal string with null char
      index = 0;                                                               // reset index to zero
      if(!in_layer_list(literal, literals, num_literals))                      // check if this literal is already in the array of found literals
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

  fclose(dnf_file);                                                            // close dnf file

  for(int i = 0; i < num_literals; i++)                                        // print out unique literals
    printf("%s\n", literals[i]);
}

void build_conjunctive_layer(char * file_name)
{
  FILE *dnf_file = fopen(file_name, "r");                                      // open dnf file
  if(dnf_file == NULL)                                                         // check dnf file opened propperly
  {
    printf("failed to open dnf_file\n");
    return;
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
  
  char *string;                                                                // string for fscanf to store part of conjunct in temporarily
  char *conjunct = malloc(sizeof(char)*MAX_LENGTH*MAX_CONJUNCTS);              // string to hold conjunct
  int num_conjuncts = 0;                                                       // keep track of number of unique conjuncts
  while(!feof(dnf_file))                                                       // loop until end of dnf file
  {
    fscanf(dnf_file, "%s", string);                                            // scan in string
    if(strncmp(string, "|", 1))                                                // if string does not equal "|"
    {
      strncat(conjunct, string, strlen(string));                               // concatenate string to conjunct string
    }
    else                                                                       // if string does equal "|"
    {
      strncpy(conjuncts[num_conjuncts], conjunct, strlen(conjunct));           // copy conjunct to array of found conjuncts
      num_conjuncts++;                                                         // increase number of found conjuncts
      strncpy(conjunct, "\0", 1);                                              // reset conjunct to empty
    }
  }
  fclose(dnf_file);                                                            // close dnf file

  for(int i = 0; i < num_conjuncts; i++)                                       // print out unique conjuncts
  {
    printf("%s\n", conjuncts[i]);
  }
}
