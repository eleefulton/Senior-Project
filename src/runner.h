#include "parse_file.h"
#include "tfidf.h"
#include "randomize.h"
#include "count_50_words.h"
#include "interpreter.h"
#include "build_network.h"
#include "build_file_name.h"
#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000
#define MAX_CATEGORIES 5
#define MAX_LENGTH 50
#define MAX_LITERALS 500
#define MAX_CONJUNCTS 500
#define ALPHA 5
#define BETA 0.025f
int in_string_list(char* string, char *list[], int n);
int verify_randomization(char **input, char **file_names_array, int *file_names_index, int num_categories, int training_size);


