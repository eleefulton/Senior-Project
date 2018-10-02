#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ALPHA 2.0f
#define BETA 0.025f
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
      sum += left_layer[j].weights[i]*left_layer[j].value;                     // sum (weights leaving left_layer[j] * left_layer[j].value)
    }
    right_layer[i].weighted_input = sum + right_layer[i].bias;                 // compute weighted input
    right_layer[i].value = sigmoid(sum);                                       // compute nodes value(output)
  }
}

/*
  compute the error for the output layer(actual) nodes based on expected layer values
*/
void compute_error_for_output(Node *actual, Node *expected, int num_output, float lr)
{
  for(int i = 0; i < num_output; i++)
  {
    float roc = actual[i].value - expected[i].value;                           // compute the rate of change of the cost function
    printf("roc = %f\n",roc); 
    printf("weighted input = %f\n", actual[i].weighted_input);
    printf("sig der = %f\n", sigmoid_derivative(actual[i].weighted_input));
    actual[i].error = roc * sigmoid_derivative(actual[i].weighted_input);      // multiply roc by the derivative of the sigmoid function of the weighted input
    actual[i].bias = actual[i].bias + actual[i].error * lr;
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
      left_layer[i].error += left_layer[i].weights[j] * right_layer[j].error;  // sum (all weights leaving left_layer[i] * error of corresponding node in right layer)
    }
    left_layer[i].error = left_layer[i].error * sigmoid_derivative(left_layer[i].weighted_input); // multiply error for left_layer[i] by sigmoid derivative of this nodes weighted input
    left_layer[i].bias = left_layer[i].bias + left_layer[i].error;
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
      float change_to_cost_func = left_layer[i].value * right_layer[j].error;  // calculate change to the cost function my multiplying this nodes value by the next layers nodes error
      left_layer[i].weights[j] = left_layer[i].weights[j] - (lr*change_to_cost_func); // adjust weight
    }
  }
}

int main(int argc, char *argv)
{
  srand(time(NULL));
  int num_input = 3;
  int input[6][3] = 
  {
    {1,0,0},
    {0,1,0},
    {0,0,1},
    {1,1,0},
    {0,1,1},
    {0,1,1}
  };
  float i_to_l_w[3][4] =
  {
    {ALPHA, -ALPHA, BETA, -BETA},
    {-BETA, BETA, -ALPHA, ALPHA},
    {-BETA, BETA, -BETA, BETA}
  }; 

  int num_literal = 4;
  float literal_biases[] = {0, 0, ALPHA, -ALPHA};
  float l_to_c_w[4][3] =
  {
    {ALPHA, -BETA, BETA},
    {BETA, ALPHA, ALPHA},
    {-BETA, ALPHA, BETA},
    {BETA, -BETA, ALPHA}
  };
 
  int num_conjunct = 3;
  float conjunct_biases[] = {(-ALPHA*(1))/2, (-ALPHA * (3))/2, (-ALPHA * (3))/2};
  float c_to_o_w[3][3] =
  {
    {ALPHA, BETA, -BETA},
    {BETA, ALPHA, -BETA},
    {-BETA, BETA, ALPHA}
  };

  int num_output = 3;
  float output_biases[] = {-0.5*ALPHA, -0.5*ALPHA, -0.5*ALPHA};
  float expected_output[6][3] = 
  {
    {1,0,0},
    {0,1,0},
    {0,0,1},
    {1,0,0},
    {0,0,1},
    {0,1,0}
  };
  float learning_rate = 0.05;

  Node *input_layer = malloc(sizeof(Node) * num_input);
  Node *literal_layer = malloc(sizeof(Node)* num_literal);
  Node *conjunct_layer = malloc(sizeof(Node) * num_conjunct);
  Node *output_layer = malloc(sizeof(Node)*num_output);
  Node *expected_output_layer = malloc(sizeof(Node)*num_output);
  
  for(int i = 0; i < num_input; i++)
  {
    input_layer[i].bias = BETA;
    input_layer[i].weights = malloc(sizeof(float)*num_literal);
  }

  for(int i = 0; i < num_literal; i++)
  {
    literal_layer[i].bias = literal_biases[i];
    literal_layer[i].weights = malloc(sizeof(float)*num_conjunct);
  }

  for(int i = 0; i < num_conjunct; i++)
  {
    conjunct_layer[i].bias = conjunct_biases[i];
    conjunct_layer[i].weights = malloc(sizeof(float)*num_output);
  }

  for(int i = 0; i < num_output; i++)
  {
    output_layer[i].bias = output_biases[i];
  }

  for(int i = 0; i < num_input; i++)
    for(int j = 0; j < num_literal; j++)
      input_layer[i].weights[j] = i_to_l_w[i][j];

  for(int i = 0; i < num_literal; i++)
    for(int j = 0; j < num_conjunct; j++)
      literal_layer[i].weights[j] = l_to_c_w[i][j];

  for(int i = 0; i < num_conjunct; i++)
    for(int j = 0; j < num_output; j++)
      conjunct_layer[i].weights[j] = c_to_o_w[i][j];

// Neural Network
for(int l = 0; l < 20000; l++)
{
  for(int i = 0; i < num_input; i++)
  {
    input_layer[i].value = input[l%6][i];
    printf("%f\n", input_layer[i].value);
  }
  for(int i = 0; i < num_output; i++)
    expected_output_layer[i].value = expected_output[l%6][i];

  forward_propagate(input_layer, literal_layer, num_input, num_literal);

  forward_propagate(literal_layer, conjunct_layer, num_literal, num_conjunct);

  forward_propagate(conjunct_layer, output_layer, num_conjunct, num_output);

  compute_error_for_output(output_layer, expected_output_layer, num_output, learning_rate);
  adjust_weights(conjunct_layer, output_layer, num_conjunct, num_output, learning_rate);

  compute_error(conjunct_layer, output_layer, num_conjunct, num_output);
  adjust_weights(literal_layer, conjunct_layer, num_literal, num_conjunct, learning_rate);

  compute_error(literal_layer, conjunct_layer, num_literal, num_conjunct);
  adjust_weights(input_layer, literal_layer, num_input, num_literal, learning_rate);

  for(int i = 0; i < num_output; i++)
  {
    printf("%f, expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
  }
  printf("\n");
}

return 0;
}
