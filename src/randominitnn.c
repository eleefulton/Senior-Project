#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "runner.h"

int random_init_nn(int num_input, int num_output, int num_hl1, int num_hl2, float learning_rate, int training_size, int sample_size)
{
  srand(time(NULL));                                                           // initalize rand()
  float bias = ALPHA;                                                          // set bias to ALPHA value
  FILE *input_file = fopen("sample_input.txt", "r");                           // open input file
  FILE *output_file = fopen("sample_output.txt", "r");                         // open expected output file
  float input[training_size][250];                                             // array to hold input values
  float expected_output[training_size][5];                                     // array to hold expected output values
  int k = 0; int p = 0;
  char c = fgetc(input_file);                                                  // get first char from input file

  for(int i = 0; i < training_size; i++)                                       // for all training input
  {
    for(int j = 0; j < num_input; j++)                                         // get each input value from file
    {
      input[i][j] = (float)(fgetc(input_file) - 48);
    }
    fgetc(input_file);                                                         // skip over newline char, move to next doc
  }

  for(int i = 0; i < training_size; i++)                                       // for each file in training set
  {
    for(int j = 0; j < num_output; j++)                                        // get expected output vlaues from file
    {
      float n = (float)(fgetc(output_file) - 48);
      expected_output[i][j] = n;
    }
    fgetc(output_file);
  }

  Node *input_layer = malloc(sizeof(Node) * num_input);                        // allocate input layer
  Node *hidden_layer_one = malloc(sizeof(Node) * num_hl1);                     // allocate literal layer
  Node *hidden_layer_two = malloc(sizeof(Node) * num_hl2);                     // allocate conjunctive layer
  Node *output_layer = malloc(sizeof(Node) * num_output);                      // allocate output layer
  Node *expected_output_layer = malloc(sizeof(Node) * num_output);             // allocate expected output layer
  
  for(int i = 0; i < num_input; i++)                                           // set all biases in input layer +/- bias
  {
    int r = rand() % 10;
    input_layer[i].bias = r > 4 ? bias : -bias;
    input_layer[i].weights = malloc(sizeof(float)*num_hl1);
  }

  for(int i = 0; i < num_hl1; i++)                                             // set all biases in literal layer to +/- bias
  {
    int r = rand() % 10;
    hidden_layer_one[i].bias = r > 4 ? bias : -bias;
    hidden_layer_one[i].weights = malloc(sizeof(float)*num_hl2);
  }

  for(int i = 0; i < num_hl2; i++)                                             // set all biases in the conjunct layer to +/- bias
  {
    int r = rand() % 10;
    hidden_layer_two[i].bias = r > 4 ? bias : -bias;
    hidden_layer_two[i].weights = malloc(sizeof(float)*num_output);
  }

  for(int i = 0; i < num_output; i++)                                          // set biases in output layer to +/- bias
  {
    int r = rand() % 10;
    output_layer[i].bias = r > 4 ? bias : -bias;
  }

  for(int i = 0; i < num_input; i++)                                          // set weights between input -> h1 to +/- [0,1]
    for(int j = 0; j < num_hl1; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        input_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else input_layer[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }

  for(int i = 0; i < num_hl1; i++)                                             // set weights between h1 -> h2 to +/- [0,1]
    for(int j = 0; j < num_hl2; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        hidden_layer_one[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else hidden_layer_one[i].weights[j] = 0 - (float)rand()/(float)(RAND_MAX);
    }

  for(int i = 0; i < num_hl2; i++)                                             // set weights between h2 -> output to +/- [0,1]
    for(int j = 0; j < num_output; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        hidden_layer_two[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else hidden_layer_two[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }

  // train RINN
  float correct = 0;
  for(int i = 0; i < ITERATIONS; i++)
  {
    for(int j = 0; j < training_size; j++)
    {
      for(int k = 0; k < num_input; k++)                                         // set input layer values
        input_layer[k].value = input[k][j];
      for(int k = 0; k < num_output; k++)                                        // set expected output layer values
        expected_output_layer[k].value = expected_output[k][j];

      // run NN
      forward_propagate(input_layer, hidden_layer_one, num_input, num_hl1);
      forward_propagate(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2);
      forward_propagate(hidden_layer_two, output_layer, num_hl2, num_output);
      compute_error_for_output(output_layer, expected_output_layer, num_output, learning_rate);
      adjust_weights(hidden_layer_two, output_layer, num_hl2, num_output, learning_rate);
      compute_error(hidden_layer_two, output_layer, num_hl2, num_output);
      adjust_weights(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2, learning_rate);
      compute_error(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2);
      adjust_weights(input_layer, hidden_layer_one, num_input, num_hl1, learning_rate);

      int max = 0;                                                               // index for max output node
      int correct_max;                                                           // index for correct output node
      for(int k = 0; k < num_output; k++)                                        // find max output node index
        if(output_layer[k].value > output_layer[max].value)
          max = k;

      for(int k = 0; k < num_output; k++)                                        // find expected output node index
        if(expected_output_layer[k].value == 1)
          correct_max = k;

      if(max == correct_max)                                                     // if indexes are the same, the network was correct
        correct++;

/*      for(int i = 0; i < num_output; i++)
      {
        printf("%f, expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
      }
      printf("\n");
*/
    }
    correct = correct / training_size * 100;                                     // compute percentage correct
//    printf("correctly categorized documents during random initialization training = %f\n", correct);
    correct = 0;
    DoProgress("training RINN: ", i+1, ITERATIONS);
  }
  printf("\n");


  correct = 0;
  // test RINN
  for(int i = 0; i < sample_size - training_size; i++)
  {
    for(int j = 0; j < num_input; j++)                                         // set input layer values
      input_layer[j].value = input[i][j];
    for(int j = 0; j < num_output; j++)                                        // set expected output layer values
      expected_output_layer[j].value = expected_output[i][j];

    // run NN
    forward_propagate(input_layer, hidden_layer_one, num_input, num_hl1);
    forward_propagate(hidden_layer_one, hidden_layer_two, num_hl1, num_hl2);
    forward_propagate(hidden_layer_two, output_layer, num_hl2, num_output);

    int max = 0;                                                               // index for max output node
    int correct_max;                                                           // index for correct output node
    for(int j = 0; j < num_output; j++)                                        // find max output node index
      if(output_layer[j].value > output_layer[max].value)
        max = j;

    for(int j = 0; j < num_output; j++)                                        // find expected output node index
      if(expected_output_layer[j].value == 1)
        correct_max = j;

    if(max == correct_max)                                                     // if indexes are the same, the network was correct
      correct++;

/*    for(int i = 0; i < num_output; i++)
    {
      printf("%f, expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
    }
    printf("\n");
*/
    DoProgress("testing RINN: ", i+1, sample_size - training_size);
  }
  printf("\n");

  correct = correct / (sample_size - training_size) * 100;                                     // compute percentage correct
  printf("correctly categorized documents during random initialization training = %f %%\n", correct);

return 0;
}
