/* interpret results of c4.5rules output
   by running c4.5 and c4.5rules and storing
   their output in *.dt and *.r files
   respectively
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  system("c4.5 -f golf > golf.dt");
  system("c4.5rules -f golf > golf.r");
  return 0;
}
