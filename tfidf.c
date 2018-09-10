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
#include "build_file_name.h"
#include "tfidf.h"


// search array of found words for given string, if it is found
// return its location, otherwise return -1
int in_list(Word found_words[], char *string, int num_words)
{
  for(int i = 0; i < num_words; i++)
  {
    if(strncmp(found_words[i].string, string, MAX_LENGTH) == 0)
      return i;
  }
  return -1;
}

/*
  comparator function for qsort
*/
int compar(const void *p, const void *q)
{
  Simple_Word *w1 = (Simple_Word*)p;
  Simple_Word *w2 = (Simple_Word*)q;
  if(w1->tfidf < w2->tfidf) return 1;
  else if(w1->tfidf > w2->tfidf) return -1;
  else return 0;
}

/*
  generate a .out file for top 50 words in each category and a .names file
  for use with the C4.5 decision tree
*/
int build_files(int unique_words, int num_categories, char *categories[], Word found_words[])
{
  Simple_Word simple_array[unique_words];
  for(int j = 0; j < unique_words; j++)
  {
    strncpy(simple_array[j].string, found_words[j].string, MAX_LENGTH);        // copy string from found words to simple array
  }

  FILE *combined_50 = fopen("./50_words/combined_50.out", "w+");
  if(combined_50 == NULL)
  {
    printf("combined_50 failed to open\n");
    return -1;
  }
  FILE *docs_names = fopen("./50_words/docs.names", "w+");
  if(docs_names == NULL)
  {
    printf("docs_names failed to open\n");
    return -1;
  }

  for(int i = 0; i < num_categories; i++)                                      // print category names to .names file
  {
    if(i+1 == num_categories)
      fprintf(docs_names, "%s.\n\n", categories[i]);
    else fprintf(docs_names, "%s, ", categories[i]);
  }

  for(int i = 0; i < num_categories; i++)                                      // sort an array of simple words for each category
  { 
    char *output_location = malloc(sizeof(char)*17);                           // create file name for output of 50 words for category
    output_location[0] = '\0';
    strncat(output_location, "./50_words/", 11);
    strncat(output_location, categories[i], 1);
    strncat(output_location, ".out", 4);
    FILE *fp = fopen(output_location, "w+");                                   // open file to store 50 most important words
    if(fp == NULL)
    {
      printf("failed to open %s: i = %d\n", output_location, i);
      return -1;
    }
    for(int j = 0; j < unique_words; j++)
      simple_array[j].tfidf = found_words[j].tfidf[i];                         // copy tfidf from found words to simple array
    qsort(simple_array, unique_words, sizeof(Simple_Word), compar);            // sort simple array
    for(int j = 0; j < MAX_LENGTH; j++)                                        // print 50 top words to files
    {
      fprintf(fp, "%s\n", simple_array[j].string);                             // print 50-words to individual files
      fprintf(combined_50, "%s\n", simple_array[j].string);                    // print 50-words to combined file
      fprintf(docs_names, "%s: continuous.\n", simple_array[j].string);        // print 50-words to .names file
    }
    fclose(fp);                                                                // close file
    free(output_location);                                                     // free name
  }
  fclose(combined_50);
  fclose(docs_names);
  return 0;
}

/* computes tfidf of words in documents in given categories
   Input: number of files to scan
*/

int tfidf(int num_categories, char *categories[], char *directory, char *file_names_array[], int file_names_index[], int sample_size)
{
  int category_lengths[num_categories];                                        // total number of words in all documents in category
  int unique_words = 0;                                                        // number of unique words found
  Word *found_words = malloc(sizeof(Word)*MAX_WORDS);                          // array of found words
  for(int i = 0; i < num_categories; i++)                                      // initalize category lengths
  {
    category_lengths[i] = 0;
  }

  for(int i = 0; i < sample_size; i++)
  {
      int category = 0;
      int index;
      int current_file_length = 0;                                             // length of current document (words)
      char *file_name = file_names_array[file_names_index[i]];
      char *string;
      FILE *fp;
      for(int j = 0; j < num_categories; j++)
      {
        if(file_names_array[file_names_index[i]][strlen(directory)] == categories[j][0])
          category = j;
      }

      fp = fopen(file_name, "r");                                              // load file

      if(fp == NULL)                                                           // check file opened properly
      {
        printf("failed to open %s\n", file_name);
        return -1;
      }
      printf("reading from %s in category %s\n", file_name, categories[category]);
      while(!feof(fp))
      {
        string = parse_next_word(fp);                                          // parse next word
        if(string[0] != '\0')                                                  // if string is not empty
        {
          current_file_length++;
          if((index = in_list(found_words, string, unique_words)) >= 0)        // check found_words[] for string
          {
            found_words[index].count[category]++;                              // if in found_words[], increment count for this category
          }
          else                                                                 // otherwise, add string to found_words[]
          {
            unique_words++;                                                    // increment count of total unique words
            strncpy(found_words[unique_words-1].string, string, MAX_LENGTH);   // copy string to found_words[]
            found_words[unique_words-1].count[category]++;                     // increment count for current category
          }
        }
      }
      fclose(fp);                                                              // close the file
      free(file_name);
      category_lengths[category] = category_lengths[category] + current_file_length;// record length of this file (words)
      current_file_length = 0;                                                 // reset current_file_length
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

  if(build_files(unique_words, num_categories, categories, found_words) >= 0)
  {
    printf("built 50-words and names file successfully\n");
  }

  return 0;
}

