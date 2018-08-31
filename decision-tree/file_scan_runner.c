/*
  Scan given file for words in the supplied 50-most-important-words file.
  firt command line argument is /path/to/50-words-file/
  second command argument is the file to scan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scan_file.h"

#define FIFTY_WORDS_SIZE 100

int main(int argc, char *argv[])
{
  FILE *fifty_words = fopen(argv[1], "r+");                                    // open file that contains 50-words
  FILE *fp = fopen("b001.txt", "r+");                                             // open file to be scanned

  char *fifty_words_array[FIFTY_WORDS_SIZE];                                   // array to hold 50-words
  int fifty_words_count[FIFTY_WORDS_SIZE];                                     // array to hold count of 50-words in doc

  if(fifty_words == NULL)
  {
    printf("failed to open 50-words file\n");
    return -1;
  }

  if(fp == NULL)
  {
    printf("failed to open file\n");
    return -1;
  }

  int i = 0;
  int j = 0;
  char c = fgetc(fifty_words);
  char string[50];

  while(c != EOF)                                                              // read 50-words form file into array
  {
    if(c == '\n')                                                              // if end of line, move to next spot in the array
    {
      string[j] = '\0';
      strncpy(fifty_words_array[i], string, strlen(string));
      for(int k = 0; k < j; k++)
        string[k] = '\0';
      i++;                                                                     // move to next spot in the array
      j = -1;                                                                  // reset to beginning of string
    }
    else string[j] = c;                                          // if not end of line, put c into string
    j++;
    c = fgetc(fifty_words);                                                    // get next char
  }

  fclose(fifty_words);                                                         // close 50-words file

  
  scan_file(fp, fifty_words_array, fifty_words_count);

  for(int k = 0; k < FIFTY_WORDS_SIZE; k++)
  {
    printf("%s: %d\n", fifty_words_array[k], fifty_words_count[k]);
  }

  return 0;
}
