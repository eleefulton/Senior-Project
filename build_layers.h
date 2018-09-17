typedef struct{
  char *tag;
  float value;
  float bias;
  float weights[];
}Node;

int initialize_input_layer(char *input_value_tags[], Node *input_layer, int n);
int initialize_literal_layer(char *file_name, Node *literal_layer);
int initialize_conjunctive_layer(char * file_name, Node *conjunctive_layer);
int initialize_output_layer(char *categories[], Node *output_layer, int n);
int in_layer_list(char* string, char *list[], int n);

#define MAX_LITERALS 500
#define MAX_CONJUNCTS 500

