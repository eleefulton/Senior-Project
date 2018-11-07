#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *test_results = fopen("test_results.csv", "w+");
  if(test_results == NULL)
  {
    printf("failed to open file\n");
    return -1;
  }
  char *command = malloc(sizeof(char)*50);
  strncat(command, "./runner ", 9);
  strncat(command, argv[1], strlen(argv[1]));
  fprintf(test_results, "nan, completed epochs, accuracy\n");
  fclose(test_results);
  for(int i = 0; i < 100; i++)
    system(command);
  return 0;
}
