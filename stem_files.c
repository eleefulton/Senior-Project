#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *file_names_file = fopen("./bbc_files/file_names.txt", "r");
  if(file_names_file == NULL)
  {
    printf("failed to open file_names.txt\n");
    return -1;
  }

  while(!feof(file_names_file))
  {
    char *name;
    fscanf(file_names_file, "%s", name);
    char *command = malloc(sizeof(char)*65);
    strncat(command, "./porter_stemmer/ps ", 20);
    strncat(command, name, strlen(name));
    strncat(command, " > ./bbc_stemmed/", 17);
    strncat(command, name + 12, 8);
    system(command);
  }

  return 0;
}
