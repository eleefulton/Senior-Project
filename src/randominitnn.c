#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "runner.h"

int random_init_nn(int num_input, int num_output, int num_hl1, int num_hl2, float learning_rate, int training_size)
{
  srand(time(NULL));
  float bias = ALPHA;
  FILE *input_file = fopen("sample_input.txt", "r");
  FILE *output_file = fopen("sample_output.txt", "r");
  float input[training_size][250];
  float expected_output[training_size][5];
  int k = 0; int p = 0;
  char c = fgetc(input_file);

  for(int i = 0; i < training_size; i++)
  {
    for(int j = 0; j < num_input; j++)
    {
      input[i][j] = (float)(fgetc(input_file) - 48);
    }
    fgetc(input_file);
  }

  for(int i = 0; i < training_size; i++)
  {
    for(int j = 0; j < num_output; j++)
    {
      float n = (float)(fgetc(output_file) - 48);
      expected_output[i][j] = n; 
    }
    fgetc(output_file);
  }
  Node *input_layer = malloc(sizeof(Node) * num_input);
  Node *hidden_layer_one = malloc(sizeof(Node) * num_hl1);
  Node *hidden_layer_two = malloc(sizeof(Node) * num_hl2);
  Node *output_layer = malloc(sizeof(Node) * num_output);
  Node *expected_output_layer = malloc(sizeof(Node) * num_output);
  
  for(int i = 0; i < num_input; i++)
  {
    input_layer[i].bias = bias;
    input_layer[i].weights = malloc(sizeof(float)*num_hl1);
  }

  for(int i = 0; i < num_hl1; i++)
  {
    hidden_layer_one[i].bias = bias;
    hidden_layer_one[i].weights = malloc(sizeof(float)*num_hl2);
  }

  for(int i = 0; i < num_hl2; i++)
  {
    hidden_layer_two[i].bias = bias;
    hidden_layer_two[i].weights = malloc(sizeof(float)*num_output);
  }

  for(int i = 0; i < num_output; i++)
  {
    output_layer[i].bias = bias;
  }

  for(int i = 0; i < num_input; i++)
    for(int j = 0; j < num_hl1; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        input_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else input_layer[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }

  for(int i = 0; i < num_hl1; i++)
    for(int j = 0; j < num_hl2; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        hidden_layer_one[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else hidden_layer_one[i].weights[j] = 0 - (float)rand()/(float)(RAND_MAX);
    }

  for(int i = 0; i < num_hl2; i++)
    for(int j = 0; j < num_output; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        hidden_layer_two[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else hidden_layer_two[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }

// Neural Network
  float correct = 0;
for(int l = 0; l < training_size; l++)
{

  for(int i = 0; i < num_input; i++)
    input_layer[i].value = input[l][i];
  for(int i = 0; i < num_output; i++)
    expected_output_layer[i].value = expected_output[l][i];

  forward_propagate(input_layer, hidden_layer_one, num_input, num_hl1);
  forward_propagate(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2);
  forward_propagate(hidden_layer_two, output_layer, num_hl2, num_output);
  compute_error_for_output(output_layer, expected_output_layer, num_output, learning_rate);
  adjust_weights(hidden_layer_two, output_layer, num_hl2, num_output, learning_rate);
  compute_error(hidden_layer_two, output_layer, num_hl2, num_output);
  adjust_weights(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2, learning_rate);
  compute_error(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2);
  adjust_weights(input_layer, hidden_layer_one, num_input, num_hl1, learning_rate);

  int max = 0;
  int correct_max;
  for(int i = 0; i < num_output; i++)
    if(output_layer[i].value > output_layer[max].value)
      max = i;

  for(int i = 0; i < num_output; i++)
    if(expected_output_layer[i].value == 1)
      correct_max = i;

  if(max == correct_max)
    correct++;

  for(int i = 0; i < num_output; i++)
  {
    printf("%f, expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
  }
  printf("\n");
}
  correct = correct / 2000;
  printf("correctly categorized documents during random initialization training = %f\n", correct);

return 0;
}
