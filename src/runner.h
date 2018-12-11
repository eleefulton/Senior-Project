#include "parse_file.h"
#include "tfidf.h"
#include "randomize.h"
#include "count_50_words.h"
#include "interpreter.h"
#include "build_network.h"
#include "build_file_name.h"
#include "randominitnn.h"
#define NUM_FILES 1
#define MAX_FILES 999
#define MAX_WORDS 100000
#define MAX_CATEGORIES 5
#define MAX_LENGTH 50
#define MAX_LITERALS 500
#define MAX_CONJUNCTS 500
#define ALPHA 1
#define BETA 0.025
#define LR 0.01
#define EPOCHS 10000
#define VALIDATION_THRESHOLD 100

int in_string_list(char* string, char *list[], int n);
int verify_randomization(char **input, char **file_names_array, int *file_names_index, int num_categories, int training_size);
double sigmoid(double x);
double sigmoid_derivative(double x);
void adjust_weights(Node *left_layer, Node *right_layer, int num_left, int num_right, double lr);
void compute_error(Node *left_layer, Node *right_layer, int num_left, int num_right);
void forward_propagate(Node *left_layer, Node *right_layer, int num_left, int num_right);
void compute_error_for_output(Node *actual, Node *expected, int num_output, double lr);
void DoProgress( char label[], int step, int total );
int count_attributes(FILE *dnf_file, char *attributes[]);

