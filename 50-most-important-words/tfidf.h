#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000
#define MAX_CATEGORIES 5

typedef struct{
  char string[50];
  int count[MAX_CATEGORIES];
  float tf[MAX_CATEGORIES];
  float idf;
  float tfidf[MAX_CATEGORIES];
}Word;

typedef struct{
  char string[50];
  float tfidf;
}Simple_Word;

int in_list(Word found_words[], char *string, int num_words);
int compar(const void *p, const void *q);
int tfidf(int argc, char *argv[]);
void build_files(int unique_words, int num_categories, char *categories[], Word found_words[]);

