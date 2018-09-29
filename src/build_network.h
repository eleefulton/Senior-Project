typedef struct{
  char *tag;
  float value;
  float bias;
  float error;
  float *weights;
  float weighted_input;
}Node;

int initialize_input_layer(char *input_value_tags[], Node *input_layer, int n);
int initialize_literal_layer(char *file_name, Node *literal_layer);
int initialize_conjunctive_layer(char * file_name, Node *conjunctive_layer);
int initialize_output_layer(char *categories[], Node *output_layer, int n);
void set_wb_input_to_literal(Node *input_layer, int num_input, Node *literal_layer, int num_literals);
void set_wb_literal_to_conjunctive(Node *literal_layer, int num_literals, Node *conjunctive_layer, int num_conjuncts);
void set_wb_conjunctive_to_output(Node *conjunctive_layer, int num_conjuncts, Node *output_layer, int num_categories);

