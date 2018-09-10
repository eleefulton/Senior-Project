#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "randomize.h"

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void randomize(int arr[], int n)
{
  srand(time(NULL));
  for(int i = n-1; i > 0; i--)
  {
    int j = rand() % (i+1);
    swap(&arr[i], &arr[j]);
  }
}
