#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_file.h"

/*
  check if the given word is in the given array of 50-words
  return 1 if it is, 0 if it's not
*/
int in_fifty_words(char *word, char *fifty_words[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(strcmp(fifty_words[i], word) == 0)
      return i;
  }
  return -1;
}

/*
  open the file whose name is file_name and count the number of time
  each word in fifty_words[] occurs in the document, storing count
  into output[]
*/
void count_fifty_words(char *file_name, char *fifty_words[], int output[], int n)
{
  FILE *fp = fopen(file_name, "r");                                            // open file
  if(fp == NULL)                                                               // check file opened propperly
  {
    printf("failed to open %s\n", file_name);
  }
  while(!feof(fp))                                                             // scan to end of file
  {
    int j = in_fifty_words(parse_next_word(fp), fifty_words, n);               // if current word is in fifty_words make j it's location
    if(j >= 0)
    {
      output[j]++;                                                             // increment count of this word in this file
    }
  }
  fclose(fp);                                                                  // close file
}

