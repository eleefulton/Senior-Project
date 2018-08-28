#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// build file name in form "000.txt" for n
char * build_name(int n)
{
  static char name[8];
  name[2] = n%10 + 48;
  n = n / 10;
  name[1] = n%10 + 48;
  n = n / 10;
  name[0] = n + 48;
  name[3] = '.';
  name[4] = 't';
  name[5] = 'x';
  name[6] = 't';
  name[7] = '\0';

  return name;
}
