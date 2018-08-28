/*
  This program builds a .names file for the data given in the ./data folder.
  Command arguments should be the location of the data files followed by
  all the categories.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE* names_file = fopen("categories.names", "w+");                          // open .names file
  FILE* combined_50_file = fopen("combined_50.txt", "w+");                     // open file to store combined 50-words
  if(names_file == NULL)                                                       // check .names file opened
  {
    printf("failed to open names file\n");
    return -1;
  }
  if(combined_50_file == NULL)
  {
    printf("failed to open combined 50 file\n");
    return -1;
  }
  
  for(int i = 2; i < argc; i++)                                                // print categories from arguments to top of file
  {
    if(i != argc-1)
      fprintf(names_file,"%s, ", argv[i]);
    else fprintf(names_file, "%s.\n\n", argv[i]);
  } 

  for(int i = 2; i < argc; i++)
  {
    char* file = malloc(sizeof(char)*(strlen(argv[1])+6));                     // create string for data file name
    strncat(file, argv[1], strlen(argv[1]));                                   // concatenate data folder to string
    strncat(file, argv[i], 1);                                                 // concatenate first category to string
    strncat(file, ".out", 4);                                                  // concatenate .out to string

    FILE* fp = fopen(file, "r");                                               // open data file
    if(fp == NULL)                                                             // check data file opened properly
    {
      printf("failed to open data file\n");
      return -1;
    }

    char c = fgetc(fp);                                                        // copy 50 words from data file to .names file
    while(c != EOF)
    {
      if(c == '\n')                                                            // if end of line add format for .names file
        fprintf(names_file, ": continuous.\n");
      else
      fputc(c, names_file);                                                    // else put char in names_file

      fputc(c, combined_50_file);                                              // add char to combined_50_file
      c = fgetc(fp);                                                           // get next char
    }

    fclose(fp);                                                                // close file
    free(file);                                                                // free string from memory
  }

  fclose(names_file);                                                          // close names_file
  fclose(combined_50_file);                                                    // close combined_50_file

  return 0;
}
