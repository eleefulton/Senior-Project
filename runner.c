#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "runner.h"

int main(int argc, char *argv[])
{
  FILE *input_file = fopen(argv[1], "r");                                     // file that contains info about categories and docs
  char *input[MAX_CATEGORIES * 2 + 5];                                        // array for input strings
  if(input_file == NULL)                                                      // check input file opened propperly
  {
    printf("Input file not opened.\n");
    return -1;
  }

  for(int i = 0; i < MAX_CATEGORIES * 2 + 5; i++)                              // allocate input array
  {
    input[i] = malloc(sizeof(char) * MAX_LENGTH);
  }

  printf("reading input file.\n");

  char c = fgetc(input_file);                                                  // read char by char from input file storing into array
  int i = 0;
  int j = 0;
  while(c != EOF)
  {
    if(c == ' ')                                                               // if char is a space, move to next spot in array
    {
      input[i][j] = '\0';
      i++;
      j = 0;
    }
    else                                                                       // otherwise add char to end of current string
    {
      input[i][j] = c;
      j++;
    }
    c = fgetc(input_file);                                                     // get next char
  }

  int num_categories = atoi(input[1]);                                         // total number of categories in data set
  int population_size = atoi(input[2]);
  int sample_size = atoi(input[3]);                                            // sample size to be used from data set
  int training_size = atoi(input[4]);
  char *categories[num_categories];                                            // array of category prefix strings
  int category_docs[num_categories];                                           // number of documents in each category
  char *fifty_words[num_categories * 50];                                      // array to hold all 50-words once computed
  char *file_names_array[population_size];                                     // array to store file names
  int file_names_index[population_size];                                       // array to store a shuffled index of file names

  if(num_categories > MAX_CATEGORIES)                                          // check there aren't too many categories
  {
    printf("Error: too many categories\n");
    return -1;
  }

  for(int i = 0, c = 5; i < num_categories; i++, c+=2)                         // get category names and number of docs in each
  {
    categories[i] = input[c];
    category_docs[i] = atoi(input[c+1]);
  }

  printf("\npopulation size = %d\n", population_size);
  printf("sample size = %d\n", sample_size);
  printf("training size = %d\n\n", training_size);
  char *file_names_name = malloc(sizeof(char)*MAX_LENGTH);
  file_names_name[0] = '\0';
  strncat(file_names_name, input[0], strlen(input[0]));
  strncat(file_names_name, "file_names.txt", strlen("file_names.txt"));

  FILE *file_names_file = fopen(file_names_name, "r");
  if(file_names_file == NULL)
  {
    printf("failed to open file_names.txt\n");
    return -1;
  }
  printf("reading file names\n");
  for(int i = 0; i < population_size; i++)                                     // allocate space in file_names_array and read name
  {
    file_names_array[i] = malloc(sizeof(char)*MAX_LENGTH);
    file_names_index[i] = i;                                                   // initalize file_names_index array
    fscanf(file_names_file, "%s", file_names_array[i]);
  }
  fclose(file_names_file);

  printf("randomizing file names index array\n");
  randomize(file_names_index, population_size);                                // randomize file names index array

  if(!verify_randomization(input, file_names_array, file_names_index,          // verify randomization hit all categories
       num_categories, training_size))
    return -1;
  
  for(int i = 0; i < num_categories * 50; i++)
  {
    fifty_words[i] = malloc(sizeof(char) * MAX_LENGTH);                        // allocate fifty_words array;
  }


  printf("computing tfidf.\n");
  if(tfidf(num_categories, categories, input[0], file_names_array, 
      file_names_index, training_size, population_size) < 0)                   // compute tfidf
  {
    printf("tfidf failed to open a file\n");
    return -1;
  }
  printf("tfidf complete\n");

  fclose(input_file);


  printf("reading 50-words.\n");
  FILE *combined_file = fopen("./50_words/combined_50.out", "r");              // open combined_50 file
  if(combined_file == NULL)                                                    // check if combined_50 opened properly
  {
    printf("failed to open 50-words\n");
    return -1;
  }

  for(int i = 0; i < num_categories * 50; i++)                                 // parse 50-words from combined file and store in array
  {
    strncpy(fifty_words[i], parse_next_word(combined_file), MAX_LENGTH);
  }
  fclose(combined_file);                                                       // close combined file

  printf("counting 50-words\n");
  FILE *docs_data = fopen("./output/docs.data", "w+");                         // open .data file
  if(docs_data == NULL)                                                        // check .data file opened correctly
  {
    printf("failed to open docs.data\n");
    return -1;
  }

  for(int i = 0; i < training_size; i++)                                       // count 50-words in training set of sample
  {
    int output[num_categories * 50];                                           // array to store count output
    for(int j = 0; j < num_categories * 50; j++)                               // initalize output array
    {  
      output[j] = 0;
    }
    count_fifty_words(file_names_array[file_names_index[i]], fifty_words, 
                        output, num_categories * 50);                          //count 50-words
    for(int j = 0; j < num_categories * 50; j++)                               // print count output to .data file
    {
      if(j+1 == num_categories * 50)                                           // if last word print new line
        fprintf(docs_data, "%d, %c\n", output[j], 
                  file_names_array[file_names_index[i]][strlen(input[0])]);
      else fprintf(docs_data, "%d, ", output[j]);
    }
  }

  printf("done counting 50-words\n");
  printf("running decision tree\n"); 
  char *dnf_file = interpreter("./output/", "docs");                           // run interpreter on decision tree output
  if(!strncmp(dnf_file, "FAILED", 6))
    return -1;
  printf("decision tree finished\n");
  

  printf("building input layer\n");
  rewind(docs_data);                                                           // rewind to beginning of docs file
  Node *input_layer = malloc(sizeof(Node)*num_categories * 50);                // create an array of Nodes for the input layer (250 words)
  initialize_input_layer(fifty_words, input_layer, num_categories * 50);       // initialize input for first file
  printf("building literal layer: \n");
  Node *literal_layer = malloc(sizeof(Node)*MAX_LITERALS);                     // create an array of Nodes for the literal layer
  int num_literals = initialize_literal_layer(dnf_file, literal_layer);        // initialize literal layer
  printf("num literals = %d\n", num_literals);
  for(int i = 0; i < num_categories*50; i++)                                   // allocate weights in input layer to num literals
  {
    input_layer[i].weights = malloc(sizeof(float)*num_literals);
    for(int j = 0; j < num_literals; j++)                                      // initialize all weights to 0
    {
      input_layer[i].weights[j] = 0;
    }
  }
  printf("building conjunctive layer: \n");
  Node *conjunctive_layer = malloc(sizeof(Node)*MAX_CONJUNCTS);                // create an array of Nodes for the conjunctive layer
  int num_conjuncts = initialize_conjunctive_layer(dnf_file, conjunctive_layer);// initialize the conjunctive layer
  printf("num conjuncts = %d\n", num_conjuncts);
  for(int i = 0; i < num_literals; i++)                                        // allocate weights in literal layer to num conjuncts
  {
    literal_layer[i].weights = malloc(sizeof(float)*num_conjuncts);
    for(int j = 0; j < num_conjuncts; j++)                                      // initialize all weights to 0
    {
      literal_layer[i].weights[j] = 0;
    }
  }
  for(int i = 0; i < num_conjuncts; i++)                                        // allocate weights in conjunctive layer to num categories
  {
    conjunctive_layer[i].weights = malloc(sizeof(float)*num_categories);
    for(int j = 0; j < num_categories; j++)                                     // initialize all weights to 0
    {
      literal_layer[i].weights[j] = 0;
    }
  }
  printf("building output layer\n");
  Node *output_layer = malloc(sizeof(Node)*num_categories);                    // create an array of Nodes for the output layer
  initialize_output_layer(categories, output_layer, num_categories);           // initalize output layer tags
  fclose(docs_data);
  printf("setting weights and biases from input to literal layer\n");
  set_wb_input_to_literal(input_layer, num_categories * 50, 
                            literal_layer, num_literals);                      // set weights and biases between input and literal layer
  for(int i = 0; i < num_categories*50; i++)
    for(int j = 0; j < num_literals; j++)
      printf("%s -%f-> %s bias %f\n", input_layer[i].tag,                      // print input-weight->literal and bias
               input_layer[i].weights[j], literal_layer[j].tag, literal_layer[j].bias);

  printf("setting weights and biases from literal layer to conjunctive layer\n");
  set_wb_literal_to_conjunctive(literal_layer, num_literals, 
                            conjunctive_layer, num_conjuncts);                 // set weights and biases between input and literal layer
  for(int i = 0; i < num_literals; i++)
    for(int j = 0; j < num_conjuncts; j++)
      printf("%s -%f-> %s bias %f\n", literal_layer[i].tag,                      // print input-weight->literal and bias
               literal_layer[i].weights[j], conjunctive_layer[j].tag, conjunctive_layer[j].bias);

  printf("setting weights and biases form conjunctive layer to output layer\n");
  set_wb_conjunctive_to_output(conjunctive_layer, num_conjuncts, output_layer, num_categories);
  for(int i = 0; i < num_conjuncts; i++)
    for(int j = 0; j < num_categories; j++)
      printf("%s -%f-> %s bias %f\n", conjunctive_layer[i].tag,                      // print input-weight->literal and bias
               conjunctive_layer[i].weights[j], output_layer[j].tag, output_layer[j].bias);
  return 0;
}

/*
  check the given list of size n for the given string
*/
int in_string_list(char* string, char *list[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(strncmp(string, list[i], MAX_LENGTH) == 0)
      return 1;
  }
  return 0;
}

int verify_randomization(char **input, char **file_names_array, int *file_names_index, int num_categories, int training_size)
{
  char check_cats[num_categories];
  int counted_cats = 0;
  for(int i = 0; i < training_size; i++)
  {
    char temp = file_names_array[file_names_index[i]][strlen(input[0])];
    int already_found = 0;
    for(int j = 0; j < counted_cats; j++)
    {
      if(temp == check_cats[j])
        already_found = 1;
    }
    if(!already_found)
    {
      check_cats[counted_cats] = temp;
      counted_cats++;
    }
  }
  if(counted_cats != num_categories)
  {
    printf("randomization failed to capture all categories\n");
    return 0;
  }
}
