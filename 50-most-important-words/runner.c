#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "parse_file.h"
#include "build_name.h"
#include "tfidf.h"

int main(int argc, char *argv[])
{
  int num_categories = atoi(argv[2]);
  char *categories[num_categories];
  int category_docs[num_categories];                                           // number of documents in each category
  int category_lengths[num_categories];                                        // total number of words in all documents in category
  if(num_categories > MAX_CATEGORIES)
  {
    printf("Error: too many categories\n");
    return -1;
  }

  for(int i = 0; i < num_categories; i++)
  {
    category_lengths[i] = 0;
  }

  for(int i = 0, c = 3; i < num_categories; i++, c+=2)
  {
    categories[i] = argv[c];
    category_docs[i] = atoi(argv[c+1]);
  }

  for(int i = 0; i < num_categories; i++)
  {
    printf("%s: %d\n", categories[i], category_docs[i]);
  }

  tfidf(num_categories, categories, category_docs, category_lengths, argv[1]);
  return 0;
}
