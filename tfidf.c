/*
  This program computes an array of each unique 
  word found in a series of documents in a category 
  and the number of times that word appears in each category. 
  It also computes an array for the lengths of each category
  measured by total number of words in all documents in
  that category.

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "parse_file.h"
#include "build_name.h"

#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000
#define MAX_CATEGORIES 5

typedef struct{
  char string[50];
  int count[MAX_CATEGORIES];
  float tf[MAX_CATEGORIES];
  float idf;
  float tfidf[MAX_CATEGORIES];
}Word;

typedef struct{
  char string[50];
  float tfidf;
}Simple_Word;

// search array of found words for given string, if it is found
// return its location, otherwise return -1
int in_list(Word found_words[], char *string, int num_words)
{
  for(int i = 0; i < num_words; i++)
  {
    if(strncmp(found_words[i].string, string, 50) == 0)
      return i;
  }
  return -1;
}

int compar(const void *p, const void *q)
{
  Simple_Word *w1 = (Simple_Word*)p;
  Simple_Word *w2 = (Simple_Word*)q;
  if(w1->tfidf < w2->tfidf) return 1;
  else if(w1->tfidf > w2->tfidf) return -1;
  else return 0;
}

/* prints the number of words in a file and the number
   of times that word appears in the file
   Input: number of files to scan
*/

int main(int argc, char *argv[])
{
  int num_categories = atoi(argv[2]);
  if(num_categories > MAX_CATEGORIES)
  {
    printf("Error: too many categories\n");
    return -1;
  }
  printf("num categories: %d\n", num_categories);
  char *categories[num_categories];
  int category_docs[num_categories];                                           // number of documents in each category
  int category_lengths[num_categories];                                        // total number of words in all documents in category
  int unique_words = 0;                                                        // number of unique words found
  Word *found_words = malloc(MAX_WORDS * sizeof(Word));

  for(int i = 0; i < num_categories; i++)
  {
    category_lengths[i] = 0;
  }

  for(int i = 0, c = 3; i < num_categories; i++, c+=2)
  {
    categories[i] = argv[c];
    category_docs[i] = atoi(argv[c+1]);
  }

  for(int i = 0; i < num_categories; i++)
  {
    printf("%s: %d\n", categories[i], category_docs[i]);
  }

  for(int i = 0; i < num_categories; i++)
  {
    for(int j = 0; j < category_docs[i]; j++)
    {
      int num_files = category_docs[i];
      int current_file_num = 1;                                                // current file in set
      int index;
      int current_file_length = 0;                                             // length of current document (words)
      char *file_name = malloc(sizeof(char)*(strlen(argv[1])+9));
      char *string;
      FILE *fp;
      strncat(file_name, argv[1], strlen(argv[1]));
      strncat(file_name, categories[i], 1);
      strncat(file_name, build_name(j+1), 7);
//      printf("%s\n", file_name);
      fp = fopen(file_name, "r");                                              // load file

      if(fp == NULL)                                                           // check file opened properly
      {
        printf("Error: FILE NOT LOADED\n");
        return -1;
      }
      while(!feof(fp))
      {
        string = parse_next_word(fp);                                          // parse next word
        if(string[0] != '\0')
        {
          current_file_length++;
          if((index = in_list(found_words, string, unique_words)) >= 0)        // check found_words[] for string
          {
            found_words[index].count[i]++;                                     // if in found_words[], increment count for this category
          }
          else                                                                 // otherwise, add string to found_words[]
          {
            unique_words++;                                                    // increment count of total unique words
            strncpy(found_words[unique_words-1].string, string, 50);           // copy string to found_words[]
            found_words[unique_words-1].count[i]++;                            // increment count for current category
          }
        }
      }
      fclose(fp);                                                              // close the file
      free(file_name);
      category_lengths[i] = category_lengths[i] + current_file_length;         // record length of this file (words)
      current_file_length = 0;                                                 // reset current_file_length
    }
  }

  for(int i = 0; i < num_categories; i++)                                      // compute term frequency per category
  {                                                                            // (term count across all docs in category / total words in category)
    for(int j = 0; j < unique_words; j++)
    {
      found_words[j].tf[i] = 
        (float)found_words[j].count[i] / category_lengths[i];
      if(found_words[j].tf[i])
      {
        found_words[j].idf++;
      }
    }
  }

  for(int i = 0; i < unique_words; i++)                                        // compute idf
  {
    found_words[i].idf = num_categories / found_words[i].idf;
  }

  for(int i = 0; i < unique_words; i++)                                        // compute tfidf
  {
    for(int j = 0;  j < num_categories; j++)
    {
      found_words[i].tfidf[j] = found_words[i].tf[j] * log(found_words[i].idf);
    }
  }

/*  for(int i = 0; i < unique_words; i++)                                        // print tfidf
  {
    printf("%s: ", found_words[i].string);
    for(int j = 0;  j < num_categories; j++)
    {
      printf("[%f]", found_words[i].tfidf[j]);
    }
    printf("\n");
  }*/

 Simple_Word simple_array[unique_words];
 for(int j = 0; j < unique_words; j++)
 {
   strncpy(simple_array[j].string, found_words[j].string, 50);                 // copy string from found words to simple array
 }

  for(int i = 0; i < num_categories; i++)                                      // sort an array of simple words for each category
  { 
    char *output_location = malloc(sizeof(char)*17);                           // create file name for output of 50 words for category
    strncat(output_location, "./50_words/", 11);
    strncat(output_location, categories[i], 1);
    strncat(output_location, ".out", 4);
    FILE *fp = fopen(output_location, "w+");                                   // open file to store 50 most important words
    for(int j = 0; j < unique_words; j++)
      simple_array[j].tfidf = found_words[j].tfidf[i];                         // copy tfidf from found words to simple array
    qsort(simple_array, unique_words, sizeof(Simple_Word), compar);            // sort simple array
    for(int j = 0; j < 50; j++)                                                // print 50 top words for category to file
    {
      fprintf(fp, "%s\n", simple_array[j].string);
    }
    fclose(fp);                                                                // close file
    free(output_location);                                                     // free name
  }

  return 0;
}
