/*
  This program computes an array for each word found
  in a series of documents. It also computes an array
  that shows how many words there are total in each
  document.

  If a word does not appear in a document, it's value
  for the corresponding documents position in the array
  will be 0.

  The number of files in the series (all files must be
  in the same directory and named using the scheme 
  XYZ.txt) will be input as the first command line
  argument.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parse_file.h"
#include "build_name.h"

#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000

typedef struct{
  char string[50];
  int count[MAX_FILES];
}Word;

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

/* prints the number of words in a file and the number
   of times that word appears in the file
   Input: number of files to scan
*/

int main(int argc, char *argv[])
{
  int num_files = atoi(argv[1]);
  FILE *fp;
  char *file_name, *string;
  Word *found_words = malloc(MAX_WORDS * sizeof(Word));
  int current_file_num = 1, total_words = 0, index, words_in_file = 0;
  int words_in_files[num_files];

  for(current_file_num; current_file_num <= num_files; current_file_num++)
  {
    file_name = build_name(current_file_num);                                   // build file name
    fp = fopen(file_name, "r");                                                 // load file
    if(fp == NULL)                                                              // check file opend properly
    {
      printf("FILE NOT LOADED\n");
      return -1;
    }
    while(!feof(fp))                                                            // loop through until end of file
    {
      string = parse_next_word(fp);                                             // parse next word
      if(string[0] != '\0')                                                     // check word is not empty
      {
        words_in_file++;                                                        // increment count of words in file
        if((index = in_list(found_words, string, total_words)) >= 0)            // otherwise, check found_words[] for string
        {
          found_words[index].count[current_file_num-1]++;                       // if in found_words[], increment count for this file
        }
        else                                                                    // otherwise, add string to found_words[]
        {
          total_words++;                                                        // increment count of total words
          strncpy(found_words[total_words-1].string, string, 50);               // copy string to found_words[]
          found_words[total_words-1].count[current_file_num-1]++;               // increment count for current file
        }
      }
    }
    fclose(fp);                                                                 // close the file
    words_in_files[current_file_num-1] = words_in_file;                         // record total number of words in this file
    words_in_file = 0;
  }

  printf("WORDS IN FILES: ");                                                   // print results
  for(int k = 0; k < num_files; k++)
  {
    printf("[%d]", words_in_files[k]);
  }
  printf("\n");
  for(int i = 0; i < total_words; i++)
  {
    printf("%s : ", found_words[i].string);
    for(int j = 0; j < num_files; j++)
    {
      printf("[%d]", found_words[i].count[j]);
    }
    printf("\n");
  }
  return 0;
}
