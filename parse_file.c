#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "runner.h"

#define STR_LEN 50

// return 1 if character is alpha value
// return 0 if character is non-alpha value
int is_alpha(char c)
{
  if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
  {
    return 1;
  }
  else
    return 0;
}

// parse through file until a single word is found
// words are seperated by ' '
// any character that is not an alpha value will be changed to ' '
char * parse_next_word(FILE *fp)
{
  static char string[STR_LEN];                                                  // string variable
  int k = 0;                                                                    // position in string
  for(int i = 0; i < STR_LEN; i++)                                              // initalize string
    string[i] = '\0';
  while(!feof(fp))                                                              // loop until end of file
  {
    string[k] = fgetc(fp);                                                      // get character
    if(!is_alpha(string[k]))                                                    // if character is non-alpha change to ' '
      string[k] = ' ';
    else if(string[k] >= 65 && string[k] <= 90)                                 // if character is capital change to lower case
      string[k] = tolower(string[k]);
    if(string[k] == ' ')                                                        // if character is ' ', end of word
    {
      string[k] = '\0';                                                         // change last character to '\0'
      return string;                                                            // return string and exit loop
    }
    k++;                                                                         // increase position in string
  }
}

