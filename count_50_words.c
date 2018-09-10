#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_file.h"

int in_fifty_words(char *word, char *fifty_words[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(strcmp(fifty_words[i], word) == 0)
      return i;
  }
  return -1;
}

void count_fifty_words(char *file_name, char *fifty_words[], int output[], int n)
{
  printf("%s\n", file_name);
  FILE *fp = fopen(file_name, "r");
  if(fp == NULL)
  {
    printf("failed to open %s\n", file_name);
  }
  while(!feof(fp))
  {
    int j = in_fifty_words(parse_next_word(fp), fifty_words, n);
    if(j >= 0)
    {
      output[j]++;
    }
  }
  fclose(fp);
}

