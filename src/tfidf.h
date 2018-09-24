
typedef struct{
  char *string;
  int *count;
  float *tf;
  float idf;
  float *tfidf;
}Word;

typedef struct{
  char *string;
  float tfidf;
}Simple_Word;

int is_in_training(int n, int arr[], int m);
int in_Word_list(Word found_words[], char *string, int num_words);
int compar(const void *p, const void *q);
int tfidf(int num_categories, char *categories[], char *directory, char *file_names_array[], int file_names_index[], int training_size, int population_size);
int build_files(int unique_words, int num_categories, char *categories[], Word found_words[]);

