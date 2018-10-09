#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "runner.h"


int main(int argc, char *argv[])
{
  FILE *input_file = fopen(argv[1], "r");                                     // file that contains info about categories and docs
  char *input[MAX_CATEGORIES * 2 + 5];                                        // array for input strings
  if(input_file == NULL)                                                      // check input file opened propperly
  {
    printf("Input file not opened.\n");
    return -1;
  }

  for(int i = 0; i < MAX_CATEGORIES * 2 + 5; i++)                              // allocate input array
  {
    input[i] = malloc(sizeof(char) * MAX_LENGTH);
  }

  printf("reading input file.\n");

  char c = fgetc(input_file);                                                  // read char by char from input file storing into array
  int i = 0;
  int j = 0;
  while(c != EOF)
  {
    if(c == ' ')                                                               // if char is a space, move to next spot in array
    {
      input[i][j] = '\0';
      i++;
      j = 0;
    }
    else                                                                       // otherwise add char to end of current string
    {
      input[i][j] = c;
      j++;
    }
    c = fgetc(input_file);                                                     // get next char
  }
  char *directory = input[0];
  int num_categories = atoi(input[1]);                                         // total number of categories in data set
  int population_size = atoi(input[2]);
  int sample_size = atoi(input[3]);                                            // sample size to be used from data set
  int training_size = atoi(input[4]);
  char *categories[num_categories];                                            // array of category prefix strings
  int category_docs[num_categories];                                           // number of documents in each category
  char *fifty_words[num_categories * 50];                                      // array to hold all 50-words once computed
  char *file_names_array[population_size];                                     // array to store file names
  int file_names_index[population_size];                                       // array to store a shuffled index of file names
  int input_values[sample_size][num_categories*50];                            // array that stores the input values for the input layer

  if(num_categories > MAX_CATEGORIES)                                          // check there aren't too many categories
  {
    printf("Error: too many categories\n");
    return -1;
  }

  int sum = 0;
  for(int i = 0, c = 5; i < num_categories; i++, c+=2)                         // get category names and number of docs in each
  {
    categories[i] = input[c];
    category_docs[i] = atoi(input[c+1]);
    sum += category_docs[i];
  }
  if(sum != population_size)
  {
    printf("population size does not match given number of files\n");
    return -1;
  }
  if(population_size < num_categories || sample_size < num_categories || training_size < num_categories)
  {
    printf("too few files to cover all categories\n");
    return -1;
  }

  printf("\npopulation size = %d\n", population_size);
  printf("sample size = %d\n", sample_size);
  printf("training size = %d\n\n", training_size);
  char *file_names_name = malloc(sizeof(char)*MAX_LENGTH);
  file_names_name[0] = '\0';
  strncat(file_names_name, input[0], strlen(input[0]));
  strncat(file_names_name, "file_names.txt", strlen("file_names.txt"));

  FILE *file_names_file = fopen(file_names_name, "r");
  if(file_names_file == NULL)
  {
    printf("failed to open file_names.txt\n");
    return -1;
  }

  for(int i = 0; i < population_size; i++)                                     // allocate space in file_names_array and read name
  {
    DoProgress("reading file names: ", i+1, population_size);
    file_names_array[i] = malloc(sizeof(char)*MAX_LENGTH);
    file_names_index[i] = i;                                                   // initalize file_names_index array
    fscanf(file_names_file, "%s", file_names_array[i]);
  }
  printf("\n");
  fclose(file_names_file);

  printf("randomizing file names index array\n");
  randomize(file_names_index, population_size);                                // randomize file names index array

  while(!verify_randomization(input, file_names_array, file_names_index,       // verify randomization hit all categories
       num_categories, training_size))
  {                                              
    printf("randomizing failed, trying again\n");                              // loop until it does
    randomize(file_names_index, population_size);
  }
  
  for(int i = 0; i < num_categories * 50; i++)
  {
    fifty_words[i] = malloc(sizeof(char) * MAX_LENGTH);                        // allocate fifty_words array;
  }


  if(tfidf(num_categories, categories, input[0], file_names_array, 
      file_names_index, training_size, population_size) < 0)                   // compute tfidf
  {
    printf("tfidf failed to open a file\n");
    return -1;
  }

  fclose(input_file);


  FILE *combined_file = fopen("./50_words/combined_50.out", "r");              // open combined_50 file
  if(combined_file == NULL)                                                    // check if combined_50 opened properly
  {
    printf("failed to open 50-words\n");
    return -1;
  }

  for(int i = 0; i < num_categories * 50; i++)                                 // parse 50-words from combined file and store in array
  {
    strncpy(fifty_words[i], parse_next_word(combined_file), MAX_LENGTH);
    DoProgress("reading 50-words: ", i+1, num_categories * 50);
  }
  fclose(combined_file);                                                       // close combined file
  printf("\n");

  FILE *docs_data = fopen("./output/docs.data", "w+");                         // open .data file
  if(docs_data == NULL)                                                        // check .data file opened correctly
  {
    printf("failed to open docs.data\n");
    return -1;
  }

  FILE *sample_input = fopen("sample_input.txt", "w+");

  for(int i = 0; i < sample_size; i++)                                         // count 50-words in sample
  {
    int output[num_categories * 50];                                           // array to store count output
    for(int j = 0; j < num_categories * 50; j++)                               // initalize output array
    {  
      output[j] = 0;
    }
    count_fifty_words(file_names_array[file_names_index[i]], fifty_words, 
                        output, num_categories * 50);                          // count 50-words
    if(i < training_size)                                                      // if this is a training file
    {
      for(int j = 0; j < num_categories * 50; j++)                             // print count output to .data file
      {
        if(j+1 == num_categories * 50)                                         // if last word print new line
          fprintf(docs_data, "%d, %c\n", output[j],                            // print category and a new line
                    file_names_array[file_names_index[i]][strlen(input[0])]);
        else fprintf(docs_data, "%d, ", output[j]);                            // if it's not a new line, only print count
      }
    }
    for(int j = 0; j < num_categories * 50; j++)                               // build input_values array for this document
    {
      input_values[i][j] = output[j] > 0 ? 1 : 0;
      fprintf(sample_input, "%d", input_values[i][j]);
    }
      fprintf(sample_input, "\n");
    DoProgress("counting 50-words: ", i+1, sample_size);
  }
  printf("\n");

  fclose(sample_input);
  printf("done counting 50-words\n");
  printf("running decision tree\n"); 
  char *dnf_file = interpreter("./output/", "docs");                           // run interpreter on decision tree output
  if(!strncmp(dnf_file, "FAILED", 6))
    return -1;
  printf("decision tree finished\n");

  printf("building input layer\n");
  rewind(docs_data);                                                           // rewind to beginning of docs file
  Node *input_layer = malloc(sizeof(Node)*num_categories * 50);                // create an array of Nodes for the input layer (250 words)
  initialize_input_layer(fifty_words, input_layer, num_categories * 50);       // initialize input for first file

  printf("building literal layer: \n");
  Node *literal_layer = malloc(sizeof(Node)*MAX_LITERALS);                     // create an array of Nodes for the literal layer
  int num_literals = initialize_literal_layer(dnf_file, literal_layer);        // initialize literal layer
  printf("num literals = %d\n", num_literals);
  for(int i = 0; i < num_categories*50; i++)                                   // allocate weights in input layer to num literals
  {
    input_layer[i].weights = malloc(sizeof(float)*num_literals);
    for(int j = 0; j < num_literals; j++)                                      // initialize all weights to 0
    {
      input_layer[i].weights[j] = 0;
    }
  }
  printf("building conjunctive layer: \n");
  Node *conjunctive_layer = malloc(sizeof(Node)*MAX_CONJUNCTS);                // create an array of Nodes for the conjunctive layer
  int num_conjuncts = initialize_conjunctive_layer(dnf_file, conjunctive_layer);// initialize the conjunctive layer
  printf("num conjuncts = %d\n", num_conjuncts);
  for(int i = 0; i < num_literals; i++)                                        // allocate weights in literal layer to num conjuncts
  {
    literal_layer[i].weights = malloc(sizeof(float)*num_conjuncts);
    for(int j = 0; j < num_conjuncts; j++)                                      // initialize all weights to 0
    {
      literal_layer[i].weights[j] = 0;
    }
  }
  for(int i = 0; i < num_conjuncts; i++)                                        // allocate weights in conjunctive layer to num categories
  {
    conjunctive_layer[i].weights = malloc(sizeof(float)*num_categories);
    for(int j = 0; j < num_categories; j++)                                     // initialize all weights to 0
    {
      literal_layer[i].weights[j] = 0;
    }
  }
  printf("building output layer\n");
  Node *output_layer = malloc(sizeof(Node)*num_categories);                    // create an array of Nodes for the output layer
  Node *expected_output_layer = malloc(sizeof(Node)*num_categories);
  for(int i = 0; i < num_categories; i++)
  {
    expected_output_layer[i].tag = categories[i];
  } 
  initialize_output_layer(categories, output_layer, num_categories);           // initalize output layer tags
  fclose(docs_data);

//  printf("\nsetting weights and biases from input to literal layer\n");
  set_wb_input_to_literal(input_layer, num_categories * 50, 
                            literal_layer, num_literals);                      // set weights and biases between input and literal layer
/*  for(int i = 0; i < num_categories*50; i++)
  {
    printf("%s\n", input_layer[i].tag);
    for(int j = 0; j < num_literals; j++)
      printf("%*s -%f-> %s bias %f\n", (int)strlen(input_layer[i].tag), "",         // print input-weight->literal and bias
               input_layer[i].weights[j], literal_layer[j].tag, literal_layer[j].bias);
  }
*/
//  printf("\nsetting weights and biases from literal layer to conjunctive layer\n");
  set_wb_literal_to_conjunctive(literal_layer, num_literals, 
                            conjunctive_layer, num_conjuncts);                 // set weights and biases between input and literal layer
/*  for(int i = 0; i < num_literals; i++)
  {
    printf("%s\n", literal_layer[i].tag);
    for(int j = 0; j < num_conjuncts; j++)
      printf("%*s -%f-> %s bias %f\n", (int)strlen(literal_layer[i].tag), "",       // print input-weight->literal and bias
               literal_layer[i].weights[j], conjunctive_layer[j].tag, conjunctive_layer[j].bias);
  }
*/
//  printf("\nsetting weights and biases form conjunctive layer to output layer\n");
  set_wb_conjunctive_to_output(conjunctive_layer, num_conjuncts, output_layer, num_categories);

/*
  for(int i = 0; i < num_conjuncts; i++)
  {
    printf("%s\n", conjunctive_layer[i].tag);
    for(int j = 0; j < num_categories; j++)
      printf("%*s -%f-> %s bias %f\n", (int)strlen(conjunctive_layer[i].tag), "",   // print input-weight->literal and bias
               conjunctive_layer[i].weights[j], output_layer[j].tag, output_layer[j].bias);
  }
*/

  FILE *sample_output = fopen("sample_output.txt", "w+");
  float correct = 0;
  for(int i = 0; i < TRAINING_ITS; i++)
  {
    for(int j = 0; j < training_size; j++)                                     // for all files in training set
    {
      char expected_output =                                                   // store expected output for this doc
             file_names_array[file_names_index[j]][strlen(directory)];
      for(int k = 0; k < num_categories; k++)
      {
        expected_output_layer[k].value = expected_output_layer[k].tag[0] == expected_output ? 1 : 0;
      }

      for(int j = 0; j < num_categories; j++)
        fprintf(sample_output, "%d", (int)expected_output_layer[j].value);
      fprintf(sample_output, "\n");

//      printf("\n\n");

      for(int k = 0; k < num_categories * 50; k++)                             // set input value for each word count for this doc
      {
        input_layer[k].value = input_values[j][k];
      }

    // run NNIDT
      forward_propagate(input_layer, literal_layer, num_categories * 50, num_literals);
      forward_propagate(literal_layer, conjunctive_layer, num_literals, num_conjuncts);
      forward_propagate(conjunctive_layer, output_layer, num_conjuncts, num_categories);
      compute_error_for_output(output_layer, expected_output_layer, num_categories, LR);
      adjust_weights(conjunctive_layer, output_layer, num_conjuncts, num_categories, LR);
      compute_error(conjunctive_layer, output_layer, num_conjuncts, num_categories);
      adjust_weights(literal_layer, conjunctive_layer, num_literals, num_conjuncts, LR);
      compute_error(literal_layer, conjunctive_layer, num_literals, num_conjuncts);
      adjust_weights(input_layer, literal_layer, num_categories * 50, num_literals, LR);

/*      int max = 0;                                                             // max output node index
      int correct_index;                                                       // correct output node index
      for(int j = 0; j < num_categories; j++)                                  // find max output node and keep track of it's index
      {
        if(output_layer[j].value > output_layer[max].value)
          max = j;
      }
      for(int j = 0; j < num_categories; j++)                                  // find index of expected output node
      {
        if(expected_output_layer[j].value == 1)
          correct_index = j;
      }
      if(max == correct_index)                                                 // if max and correct_index are the same, the network was correct
        correct++;
*/
/*      for(int j = 0; j < num_categories; j++)                                    // print output of network
          printf("actual: %f expected: %f\n", output_layer[j].value, expected_output_layer[j].value);
*/
    }
//    correct = correct / training_size * 100;                                   // compute percent correct
//    printf("correctly categorized documents during training: %f %%\n\n", correct); // print percent correct during training
//    correct = 0;
    DoProgress("training NNIDT: ", i+1, TRAINING_ITS);
  }
  printf("\n");
  fclose(sample_output);                                                       // close sample_output file for rinn to use

// test NNIDT
  for(int i = 0; i < (sample_size - training_size); i++)
  {
    char expected_output =                                                     // store expected output for this doc
           file_names_array[file_names_index[i]][strlen(directory)];
    for(int j = 0; j < num_categories; j++)
    {
      if(expected_output_layer[j].tag[0] == expected_output)
        expected_output_layer[j].value = 1;
      else
        expected_output_layer[j].value = 0;
    }

    for(int j = 0; j < num_categories * 50; j++)                               // set input value for each word count for this doc
    {
      input_layer[j].value = input_values[i][j];
    }

    // run NNIDT
    forward_propagate(input_layer, literal_layer, num_categories * 50, num_literals);
    forward_propagate(literal_layer, conjunctive_layer, num_literals, num_conjuncts);
    forward_propagate(conjunctive_layer, output_layer, num_conjuncts, num_categories);

    int max = 0;
    int correct_index;
    for(int j = 0; j < num_categories; j++)
    {
      if(output_layer[j].value > output_layer[max].value)
        max = j;
    }
    for(int j = 0; j < num_categories; j++)
    {
      if(expected_output_layer[j].value == 1)
        correct_index = j;
    }
    if(max == correct_index)
    {
  //    printf("correct\n");
      correct++;
    }
  //  else printf("wrong\n");
    DoProgress("testing NNIDT: ", i+1, sample_size - training_size);
  }
  printf("\n");
  correct = correct / (sample_size - training_size) * 100;                     // compute percent correct
  printf("correctly categorized documents during testing: %f %%\n\n", correct); // print percent correct during training

  //random_init_nn(num_categories * 50, num_categories, num_literals, num_conjuncts, LR, training_size, sample_size); // run rinn on same training set

  return 0;
}

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
//    printf("roc = %f\n",roc); 
//    printf("weighted input = %f\n", actual[i].weighted_input);
//    printf("sig der = %f\n", sigmoid_derivative(actual[i].weighted_input));
    actual[i].error = roc * sigmoid_derivative(actual[i].weighted_input);      // multiply roc by the derivative of the sigmoid function of the weighted input
//    actual[i].bias = actual[i].bias + actual[i].error * lr;
//    printf("error for output [%d] = %f\n", i, actual[i].error);
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
//    left_layer[i].bias = left_layer[i].bias + left_layer[i].error;
//    printf("error for left_layer[%d] = %f\n", i, left_layer[i].error);
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

/*
  check the given list of size n for the given string
*/
int in_string_list(char* string, char *list[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if(strncmp(string, list[i], MAX_LENGTH) == 0)
      return 1;
  }
  return 0;
}

/*
  verify that randomization of files resulted in at least one
  file from every category in the training set
*/
int verify_randomization(char **input, char **file_names_array, int *file_names_index, int num_categories, int training_size)
{
  char check_cats[num_categories];
  int counted_cats = 0;
  for(int i = 0; i < training_size; i++)
  {
    char temp = file_names_array[file_names_index[i]][(int)strlen(input[0])];
    int already_found = 0;
    for(int j = 0; j < counted_cats; j++)
    {
      if(temp == check_cats[j])
        already_found = 1;
    }
    if(!already_found)
    {
      check_cats[counted_cats] = temp;
      counted_cats++;
    }
  }
  if(counted_cats != num_categories)
  {
    return 0;
  }
  return 1;
}

/*
  https://www.codeproject.com/Tips/537904/Console-simple-progress
  CPOL 1.02
*/
void DoProgress( char label[], int step, int total )
{
    //progress width
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int pwidth = w.ws_col - 10;

    //minus label len
    int width = pwidth - 50;
    int pos = ( step * width ) / total ;

    
    int percent = ( step * 100 ) / total;

    //set green text color, only on Windows
//    SetConsoleTextAttribute(  GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN );
    printf( "%s%*c[", label, 50 - (int)strlen(label), ' ');

    //fill progress bar with #
    for ( int i = 0; i < pos; i++ )  printf( "%c", '#' );

    //fill progress bar with spaces
    printf( "%*c%c", width - pos + 1, ' ', ']' );
    printf( " %3d%%\r", percent );

    //reset text color, only on Windows
//    SetConsoleTextAttribute(  GetStdHandle( STD_OUTPUT_HANDLE ), 0x08 );
}
