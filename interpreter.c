/* interpret results of c4.5rules output
   by running c4.5 and c4.5rules and storing
   their output in *.dt and *.r files
   respectively
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "tfidf.h"

void interpreter(char *path, char *name)
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;
  char *command1 = malloc(sizeof(char)*MAX_LENGTH);
  command1[0] = '\0';
  char *command2 = malloc(sizeof(char)*MAX_LENGTH);
  command2[0] = '\0';
  char *rules_file_name = malloc(sizeof(char)*MAX_LENGTH);
  rules_file_name[0] = '\0';

  strncat(rules_file_name, name, strlen(name));
  strncat(rules_file_name, ".r", 2);

  strncat(command1, "c4.5 -f ", 8);
  strncat(command1, path, strlen(path));
  strncat(command1, name, strlen(name));
  strncat(command1, " > ", 3);
  strncat(command1, name, strlen(name));
  strncat(command1, ".dt", 3);

  strncat(command2, "c4.5rules -f ", 13);
  strncat(command2, path, strlen(path));
  strncat(command2, name, strlen(name));
  strncat(command2, " > ", 3);
  strncat(command2, name, strlen(name));
  strncat(command2, ".r", 2);  

  printf("%s\n", command1);
  printf("%s\n", command2);
  system(command1);
  system(command2);

  fp = fopen(rules_file_name, "r");                                            // open rules file
  if(fp == NULL)
  {
    printf("Failed to open \n");
  }

  while((read = getline(&line, &len, fp)) != -1)                               // read each line of rules file
  {
    if(!strncmp(line, "Final rules from tree 0:", 24))                         // find beginning of rules
    {
      break;
    }
  }

  while(((read = getline(&line, &len, fp)) != -1 ) &&                          // print out all rules
        (strncmp(line,"Default class:", 14)))
  {
      printf("%s", line);
  }
  fclose(fp);
}
