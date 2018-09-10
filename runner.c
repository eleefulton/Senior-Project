#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "parse_file.h"
#include "tfidf.h"
#include "randomize.h"
#include "count_50_words.h"
#include "interpreter.h"

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

  printf("\npopulation size = %d\n", population_size);
  printf("sample size = %d\n", sample_size);
  printf("training size = %d\n\n", training_size);

  printf("opening file_names.txt\n");                                          // open file that contains all bbc dataset file names
  FILE *file_names_file = fopen("./bbc_files/file_names.txt", "r");
  if(file_names_file == NULL)
  {
    printf("failed to open file_names.txt\n");
    return -1;
  }
  for(int i = 0; i < population_size; i++)                                     // allocate space in file_names_array and read name
  {
    file_names_array[i] = malloc(sizeof(char)*MAX_LENGTH);
    file_names_index[i] = i;                                                   // initalize file_names_index array
    fscanf(file_names_file, "%s", file_names_array[i]);
  }
  fclose(file_names_file);

  printf("randomizing file_names_array\n");
  randomize(file_names_index, population_size);

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


  for(int i = 0; i < num_categories * 50; i++)
  {
    fifty_words[i] = malloc(sizeof(char) * MAX_LENGTH);                        // allocate fifty_words array;
  }


  printf("computing tfidf.\n");
  if(tfidf(num_categories, categories, input[0], file_names_array, file_names_index, training_size, population_size) < 0)          // compute tfidf
  {
    printf("tfidf failed\n");
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
  FILE *docs_data = fopen("./50_words/docs.data", "w+");                       // open .data file
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
    count_fifty_words(file_names_array[file_names_index[i]], fifty_words, output, num_categories * 50); //count 50-words
    for(int j = 0; j < num_categories * 50; j++)                               // print count output to .data file
    {
      if(j+1 == num_categories * 50)                                           // if last word print new line
        fprintf(docs_data, "%d, %c\n", output[j], file_names_array[file_names_index[i]][strlen(input[0])]);
      else fprintf(docs_data, "%d, ", output[j]);
    }
  }

  printf("done counting 50-words\n");
  printf("running decision tree\n"); 
  interpreter("./50_words/", "docs");
  printf("decision tree finished\n");

  return 0;
}
