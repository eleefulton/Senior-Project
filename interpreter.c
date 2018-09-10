/* interpret results of c4.5rules output
   by running c4.5 and c4.5rules and storing
   their output in *.dt and *.r files
   respectively
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interpreter(char *)
{

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  system("c4.5 -f golf > golf.dt");
  system("c4.5rules -f golf > golf.r");

  fp = fopen("golf.r", "r");                                               // open rules file
  if(fp == NULL)
  {
    printf("Failed to oepn file\n");
    return 0;
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
  
  return 0;
}
