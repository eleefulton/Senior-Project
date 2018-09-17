/* interpret results of c4.5rules output
   by running c4.5 and c4.5rules and storing
   their output in *.dt and *.r files
   respectively, then read from the .r file
   and print the disjunctive normal form
   to the .dnf file and returns the name
   of the .dnf file as a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "tfidf.h"

char* interpreter(char *path, char *name)
{
  FILE *rules_file;                                                            // file pointer for rules file
  FILE *rules_condensed;                                                       // file pointer for condensed rules file
  char *line = NULL;                                                           // string pointer for current line of file
  size_t len = 0;                                                              // size of line
  size_t read;                                                                 // length of line read
  char *command1 = malloc(sizeof(char)*MAX_LENGTH);                            // first command for c4.5
  command1[0] = '\0';                                                          // initialize first command to empty string
  char *command2 = malloc(sizeof(char)*MAX_LENGTH);                            // second command for c4.5
  command2[0] = '\0';                                                          // initalize second command to empty string
  char *rules_file_name = malloc(sizeof(char)*MAX_LENGTH);                     // rules file name
  rules_file_name[0] = '\0';                                                   // initalize rules file name to empty string
  char *rules_condensed_name = malloc(sizeof(char)*MAX_LENGTH);                // condensed rules file name
  rules_condensed_name[0] = '\0';                                              // initalize rules condensed name to empty string

  strncat(rules_file_name, name, strlen(name));                                // concatenate name to rules file name
  strncat(rules_file_name, ".r", 2);                                           // contatenate '.r' to rules file name

  strncat(rules_condensed_name, name, strlen(name));                           // concatenate name to rules condensed name
  strncat(rules_condensed_name, ".dnf", 15);                                   // concatenate ".dnf" to rules condensed name

  strncat(command1, "c4.5 -f ", 8);                                            // build command 1
  strncat(command1, path, strlen(path));
  strncat(command1, name, strlen(name));
  strncat(command1, " > ", 3);
  strncat(command1, name, strlen(name));
  strncat(command1, ".dt", 3);

  strncat(command2, "c4.5rules -f ", 13);                                      // build command 2
  strncat(command2, path, strlen(path));
  strncat(command2, name, strlen(name));
  strncat(command2, " > ", 3);
  strncat(command2, name, strlen(name));
  strncat(command2, ".r", 2);  

  printf("%s\n", command1);                                                    // print command 1
  printf("%s\n", command2);                                                    // print command 2
  system(command1);                                                            // call command 1 from system
  system(command2);                                                            // call command 2 from system

  rules_file = fopen(rules_file_name, "r");                                    // open rules file
  rules_condensed = fopen(rules_condensed_name, "w+");                         // open rules condensed file
  if(rules_file == NULL)                                                       // check rules file opened propperly
  {
    printf("Failed to open %s\n", rules_file_name);
  }
  if(rules_condensed == NULL)
  {
    printf("Failed to open %s\n", rules_condensed_name);
  }

  while((read = getline(&line, &len, rules_file)) != -1)                       // read each line of rules file
  {
    if(!strncmp(line, "Final rules from tree 0:", 24))                         // find beginning of rules
    {
      break;
    }
  }

  while(((read = getline(&line, &len, rules_file)) != -1 ) &&                  // print out all rules until the line 'Default class:'
         (strncmp(line,"Default class:", 14)))
  {
      if(strncmp(line, "Rule", 4))                                             // skip lines that start with 'Rule'
      {
        if(!strncmp(line,"\t->", 3))                                           // skip lines that start with '	->', new rule
        {
          fseek(rules_condensed, -2L, SEEK_CUR);                               // move back two spots in file
          fprintf(rules_condensed, "%.1s ", line + 11);                        // mark what the conjuncts expected output is
          fprintf(rules_condensed, "| ");                                      // print '|' to represent or
        }
        else if(strncmp(line, "\n", 1))                                        // skip lines that are blank
        {
          line[strlen(line)-1] = '\0';                                         // remove new line from end of string
          fprintf(rules_condensed, "%s & ", line + 5);                         // print line to file
        }
      }
  }
  fseek(rules_condensed, -2L, SEEK_CUR);
  fprintf(rules_condensed, "\n");
  fclose(rules_file);
  fclose(rules_condensed);
  return rules_condensed_name;
}
