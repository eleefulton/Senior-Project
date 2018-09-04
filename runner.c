#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "parse_file.h"
#include "build_name.h"
#include "tfidf.h"

int main(int argc, char *argv[])
{
  int num_categories = atoi(argv[2]);                                          // number of categories
  char *categories[num_categories];                                            // array of category prefix strings
  int category_docs[num_categories];                                           // number of documents in each category
  char *fifty_words[num_categories*50];                                        // array to hold all 50-words once computed

  if(num_categories > MAX_CATEGORIES)                                          // check there aren't too many categories
  {
    printf("Error: too many categories\n");
    return -1;
  }

  for(int i = 0, c = 3; i < num_categories; i++, c+=2)                         // get category names and number of docs in each
  {
    categories[i] = argv[c];
    category_docs[i] = atoi(argv[c+1]);
  }

  for(int i = 0; i < num_categories * 50; i++)
  {
    fifty_words[i] = malloc(sizeof(char)*50);                                  // allocate fifty_words array;
  }

  printf("computing tfidf\n");
  tfidf(num_categories, categories, category_docs, argv[1]);                   // compute tfidf

  printf("reading 50-words\n");
  FILE *fp = fopen("./50_words/combined_50.out", "r");                         // open combined_50 file
  if(fp == NULL)                                                               // check if combined_50 opened properly
  {
    printf("failed to open 50-words\n");
    return -1;
  }

  for(int i = 0; i < num_categories * 50; i++)                                 // parse 50-words from combined file and store in array
  {
    strncpy(fifty_words[i], parse_next_word(fp), 50);
  }
  fclose(fp);


  return 0;
}
