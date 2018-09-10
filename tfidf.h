#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000
#define MAX_CATEGORIES 5
#define MAX_LENGTH 50

typedef struct{
  char string[MAX_LENGTH];
  int count[MAX_CATEGORIES];
  float tf[MAX_CATEGORIES];
  float idf;
  float tfidf[MAX_CATEGORIES];
}Word;

typedef struct{
  char string[MAX_LENGTH];
  float tfidf;
}Simple_Word;

int in_list(Word found_words[], char *string, int num_words);
int compar(const void *p, const void *q);
int tfidf(int num_categories, char *categories[], char *directory, char *file_names_array[], int file_names_index[], int sample_size);
int build_files(int unique_words, int num_categories, char *categories[], Word found_words[]);

