#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

/*
  https://www.codeproject.com/Tips/537904/Console-simple-progress
  CPOL 1.02
*/
void DoProgress( char label[], int step, int total )
{
    //progress width
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int pwidth = w.ws_col - 10;

    //minus label len
    int width = pwidth - 50;
    int pos = ( step * width ) / total ;

    
    int percent = ( step * 100 ) / total;

    //set green text color, only on Windows
//    SetConsoleTextAttribute(  GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN );
    printf( "%s%*c[", label, 50 - (int)strlen(label), ' ');

    //fill progress bar with #
    for ( int i = 0; i < pos; i++ )  printf( "%c", '#' );

    //fill progress bar with spaces
    printf( "%*c%c", width - pos + 1, ' ', ']' );
    printf( " %3d%%\r", percent );

    //reset text color, only on Windows
//    SetConsoleTextAttribute(  GetStdHandle( STD_OUTPUT_HANDLE ), 0x08 );
}

int main(int argc, char *argv[])
{
  for(int i = 0; i < 10000; i++)
  {
    printf("%d\n", i);
    printf("progress bar goes here\n");
//    DoProgress("loading: ", i+1, 10000);
  }
  printf("\n");
  return 0;
}
