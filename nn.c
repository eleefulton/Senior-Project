#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct{
  char *tag;
  float value;
  float bias;
  float error;
  float *weights;
  float weighted_input;
}Node;

/*
  return result of sigmoid funciton on x
*/
float sigmoid(float x)
{
  float e = exp((float)-x);
  return (float)1/(1 + e);
}

/*
  return the result of the derivative of the sigmoid function with regards to x
*/
float sigmoid_derivative(float x)
{
  float e = sigmoid((float)x);
  return (float)e * (1 - e);
}

/*
  compute activation in right_layer based on left_layer
*/
void forward_propagate(Node *left_layer, Node *right_layer, int num_left, int num_right)
{
  for(int i = 0; i < num_right; i++)
  {
    float sum = 0;
    for(int j = 0; j < num_left; j++)
    {
      sum += left_layer[j].weights[i]*left_layer[j].value;
    }
    right_layer[i].weighted_input = sum + right_layer[i].bias;
    right_layer[i].value = sigmoid(sum);
  }
}

/*
  compute the error for the output layer(actual) nodes based on expected layer values
*/
void compute_error_for_output(Node *actual, Node *expected, int num_output, float lr)
{
  for(int i = 0; i < num_output; i++)
  {
    float roc = actual[i].value - expected[i].value;
    printf("roc = %f\n",roc); 
    printf("weighted input = %f\n", actual[i].weighted_input);
    printf("sig der = %f\n", sigmoid_derivative(actual[i].weighted_input));
    actual[i].error = roc * sigmoid_derivative(actual[i].weighted_input);
//    actual[i].bias = actual[i].bias + actual[i].error * lr;
    printf("error for output [%d] = %f\n", i, actual[i].error);
  }
}

/*
  compute error for left_layer based on right_layer
*/
void compute_error(Node *left_layer, Node *right_layer, int num_left, int num_right)
{
  for(int i = 0; i < num_left; i++)
  {
    for(int j = 0; j < num_right; j++)
    {
      left_layer[i].error += left_layer[i].weights[j] * right_layer[j].error;
    }
    left_layer[i].error = left_layer[i].error * sigmoid_derivative(left_layer[i].weighted_input);
//    left_layer[i].bias = left_layer[i].bias + left_layer[i].error;
    printf("error for left_layer[%d] = %f\n", i, left_layer[i].error);
  }
}

/*
  adjust weights going from left_layer to right_layer using learning rate (lr)
*/
void adjust_weights(Node *left_layer, Node *right_layer, int num_left, int num_right, float lr)
{
  for(int i = 0; i < num_left; i++)
  {
    for(int j = 0; j < num_right; j++)
    {
      float change_to_cost_func = left_layer[i].value * right_layer[j].error;
      left_layer[i].weights[j] = left_layer[i].weights[j] - (lr*change_to_cost_func);
    }
  }
}

int main(int argc, char *argv)
{
  srand(time(NULL));
  int num_input = 2;
  int num_hidden = 6;
  int num_output = 2;
  float learning_rate = 0.05;
  float bias = 0.5;

  Node *input_layer = malloc(sizeof(Node) * num_input);
  Node *hidden_layer = malloc(sizeof(Node)* num_hidden);
  Node *output_layer = malloc(sizeof(Node)*num_output);
  Node *expected_output_layer = malloc(sizeof(Node)*num_output);
  
  for(int i = 0; i < num_input; i++)
  {
    input_layer[i].bias = bias;
    input_layer[i].weights = malloc(sizeof(float)*num_hidden);
  }

  for(int i = 0; i < num_hidden; i++)
  {
    hidden_layer[i].bias = bias;
    hidden_layer[i].weights = malloc(sizeof(float)*num_output);
  }

  for(int i = 0; i < num_output; i++)
  {
    output_layer[i].bias = bias;
  }

  for(int i = 0; i < num_input; i++)
    for(int j = 0; j < num_hidden; j++)
      input_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
//      input_layer[i].weights[j] = 0.5;

  for(int i = 0; i < num_hidden; i++)
    for(int j = 0; j < num_output; j++)
    hidden_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
  //    hidden_layer[i].weights[j] = 0.5;

// Neural Network
for(int l = 0; l < 2000; l++)
{
//  int a = 1;
  int a = rand() % 2;
  input_layer[0].value = a;
  input_layer[1].value = (a + 1) % 2;
  expected_output_layer[0].value = (a + 1) % 2;
  expected_output_layer[1].value = a;

  forward_propagate(input_layer, hidden_layer, num_input, num_hidden);
  for(int i = 0; i < num_input; i++)
  {
    printf("input node [%d]: value = %f\n", i, input_layer[i].value);
    for(int j = 0; j < num_hidden; j++)
      printf("  -%f-> hidden %f\n", input_layer[i].weights[j], hidden_layer[j].value);
  }

  forward_propagate(hidden_layer, output_layer, num_hidden, num_output);
  for(int i = 0; i < num_hidden; i++)
  {
    printf("hidden node [%d]: value = %f\n", i, hidden_layer[i].value);
    for(int j = 0; j < num_output; j++)
      printf("  -%f-> output %f\n", hidden_layer[i].weights[j], output_layer[j].value);
  }

  compute_error_for_output(output_layer, expected_output_layer, num_output, learning_rate);
  adjust_weights(hidden_layer, output_layer, num_hidden, num_output, learning_rate);
  for(int i = 0; i < num_hidden; i++)
  {
    printf("hidden node [%d]: value = %f\n", i, hidden_layer[i].value);
    for(int j = 0; j < num_output; j++)
      printf("  <-%f- output %f\n", hidden_layer[i].weights[j], output_layer[j].value);
  }

  compute_error(hidden_layer, output_layer, num_hidden, num_output);
  adjust_weights(input_layer, hidden_layer, num_input, num_hidden, learning_rate);
  for(int i = 0; i < num_input; i++)
  {
    printf("input node [%d]: vlaue = %f\n", i, input_layer[i].value);
    for(int j = 0; j < num_hidden; j++)
      printf("  <-%f- hidden %f\n", input_layer[i].weights[j], hidden_layer[j].value);
  }

  for(int i = 0; i < num_output; i++)
  {
    printf("%f, expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
  }
  printf("\n");
}

return 0;
}
