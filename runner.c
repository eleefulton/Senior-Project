#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "parse_file.h"
#include "tfidf.h"

int main(int argc, char *argv[])
{
  FILE *input_file = fopen(argv[1], "r");                                     // file that contains info about categories and docs
  char *input[MAX_CATEGORIES * 2 + 2];                                        // array for input strings
  if(input_file == NULL)                                                      // check input file opened propperly
  {
    printf("Input file not opened.\n");
    return -1;
  }

  for(int i = 0; i < MAX_CATEGORIES * 2 + 2; i++)                              // allocate input array
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

  int num_categories = atoi(input[1]);
  char *categories[num_categories];                                            // array of category prefix strings
  int category_docs[num_categories];                                           // number of documents in each category
  char *fifty_words[num_categories * 50];                                      // array to hold all 50-words once computed

  if(num_categories > MAX_CATEGORIES)                                          // check there aren't too many categories
  {
    printf("Error: too many categories\n");
    return -1;
  }

  for(int i = 0, c = 2; i < num_categories; i++, c+=2)                         // get category names and number of docs in each
  {
    categories[i] = input[c];
    category_docs[i] = atoi(input[c+1]);
  }


  for(int i = 0; i < num_categories * 50; i++)
  {
    fifty_words[i] = malloc(sizeof(char) * MAX_LENGTH);                        // allocate fifty_words array;
  }


  printf("computing tfidf.\n");
  tfidf(num_categories, categories, category_docs, input[0]);                  // compute tfidf

  fclose(input_file);
  for(int i = 0; i < MAX_CATEGORIES * 2 + 2; i++)
  {
    free(input[i]);
  }

  fclose(input_file);                                                          // close input_file

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
  fclose(combined_file);


  return 0;
}
