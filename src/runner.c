#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "runner.h"


int main(int argc, char *argv[])
{
//  srand(time(NULL));

FILE *test_results = fopen("test_results.csv", "a");
for(int test = 0; test < 1; test++)
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
    input_layer[i].weights = malloc(sizeof(double)*num_literals);
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
    literal_layer[i].weights = malloc(sizeof(double)*num_conjuncts);
    for(int j = 0; j < num_conjuncts; j++)                                      // initialize all weights to 0
    {
      literal_layer[i].weights[j] = 0;
    }
  }
  for(int i = 0; i < num_conjuncts; i++)                                        // allocate weights in conjunctive layer to num categories
  {
    conjunctive_layer[i].weights = malloc(sizeof(double)*num_categories);
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
/*
   uncomment to run NNIDT
*/
/*  set_wb_input_to_literal(input_layer, num_categories * 50, 
                            literal_layer, num_literals);                      // set weights and biases between input and literal layer
  set_wb_literal_to_conjunctive(literal_layer, num_literals, 
                            conjunctive_layer, num_conjuncts);                 // set weights and biases between input and literal layer
  set_wb_conjunctive_to_output(conjunctive_layer, num_conjuncts, output_layer, num_categories);
*/
/*
   uncomment to run RINN
*/
  for(int i = 0; i < num_categories*50; i++)                                          // set weights between input -> literal to +/- [0,1]
  {
    for(int j = 0; j < num_literals; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        input_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else input_layer[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }
    int r = rand() % 10;
    input_layer[i].bias = r > 4 ? ALPHA : -ALPHA;
  }
  for(int i = 0; i < num_literals; i++)                                          // set weights between literal -> conjunctive to +/- [0,1]
  {
    for(int j = 0; j < num_conjuncts; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        literal_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else literal_layer[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }
    int r = rand() % 10;
    input_layer[i].bias = r > 4 ? ALPHA : -ALPHA;
  }
  for(int i = 0; i < num_conjuncts; i++)                                          // set weights between conjunctive -> output to +/- [0,1]
  {
    for(int j = 0; j < num_categories; j++)
    {
      int r = rand() % 10;
      if(r < 5)
        conjunctive_layer[i].weights[j] = (float)rand() / (float)(RAND_MAX);
      else conjunctive_layer[i].weights[j] = 0 - (float)rand() / (float)(RAND_MAX);
    }
    int r = rand() % 10;
    input_layer[i].bias = r > 4 ? ALPHA : -ALPHA;
  }


  for(int i = 0; i < num_conjuncts; i++)
  {
    for(int j = 0; j < num_categories; j++)
      printf("%f\n", conjunctive_layer[i].weights[j]);
  }


  Node *previous_input = malloc(sizeof(Node)*num_categories*50);
  for(int i = 0; i < num_categories*50; i++)
    previous_input[i].weights = malloc(sizeof(double)*num_literals);

  Node *previous_literal = malloc(sizeof(Node)*num_literals);
  for(int i = 0; i < num_literals; i++)
    previous_literal[i].weights = malloc(sizeof(double)*num_conjuncts);

  Node *previous_conjunctive = malloc(sizeof(Node)*num_conjuncts);
  for(int i = 0; i < num_conjuncts; i++)
    previous_conjunctive[i].weights = malloc(sizeof(double)*num_categories);

  Node *previous_output = malloc(sizeof(Node)*num_categories);




  FILE *sample_output = fopen("sample_output.txt", "w+");
  int stop = 0;
  int completed_epochs = EPOCHS;                                              // keep track of how many epochs the network completes
  double previous_best = 0;                                                   // keep track of network's previous best accuracy
  double correct = 0;
  int training_set_size = training_size / 10 * 9;                            // split training set into training and validation using 9:1
  int validation_set_size = training_size / 10;
  printf("\ntraining set size = %d\n", training_set_size);
  printf("validation set size = %d\n", validation_set_size);
  printf("validation threshold = %d epochs\n\n", VALIDATION_THRESHOLD);
  for(int i = 0; i < EPOCHS && stop != 1; i++)                                     // loop through 1000 epochs or until early stop condition
  {

//    for(int j = 0; j < num_categories * 50; j++)
      if(input_layer[j].value < 0)
        printf("input node %d less than zero\n", j);
    for(int j = 0; j < num_categories * 50; j++)
      if(input_layer[j].value != input_layer[j].value)
        printf("nan in input node %d\n", j);
    for(int j = 0; j < num_literals; j++)
      if (literal_layer[j].value != literal_layer[j].value)
        printf("nan in literal node %d\n", j);
    for(int j = 0; j < num_conjuncts; j++)
      if (conjunctive_layer[j].value != conjunctive_layer[j].value)
        printf("nan in conjunctive node %d\n", j);
    for(int j = 0; j < num_categories; j++)
      if (output_layer[j].value != output_layer[j].value)
        printf("nan in output node %d\n", j);
//
//    printf("training set size: %d\n", training_set_size);
//    printf("validation set size: %d\n", validation_set_size);

//    if(i % 5 == 0)                                                             // store the network to be used for validation as previous network
    {
      for(int j = 0; j < num_categories * 50; j++)
      {
        previous_input[j].value = input_layer[j].value;
        previous_input[j].bias = input_layer[j].bias;
        for(int k = 0; k < num_literals; k++)
          previous_input[j].weights[k] = input_layer[j].weights[k];
      }

      for(int j = 0; j < num_literals; j++)
      {
        previous_literal[j].value = literal_layer[j].value;
        previous_literal[j].bias = literal_layer[j].bias;
        for(int k = 0; k < num_conjuncts; k++)
          previous_literal[j].weights[k] = literal_layer[j].weights[k];
      }

      for(int j = 0; j < num_conjuncts; j++)
      {
        previous_conjunctive[j].value = conjunctive_layer[j].value;
        previous_conjunctive[j].bias = conjunctive_layer[j].bias;
        for(int k = 0; k < num_categories; k++)
          previous_conjunctive[j].weights[k] = conjunctive_layer[j].weights[k];
      }

      for(int j = 0; j < num_categories; j++)
      {
        previous_output[j].value = output_layer[j].value;
        previous_output[j].bias = output_layer[j].bias;
      }
    }

    for(int j = 0; j < training_set_size; j++)                                 // for all files in training set
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
  
      int max = 0;
      int correct_index = 0;
      for(int k = 0; k < num_categories; k++)                                // compute if the network got this one correct
      {
        if(output_layer[k].value > output_layer[max].value)
          max = k;
      }
      for(int k = 0; k < num_categories; k++)
      {
        if(expected_output_layer[k].value == 1)
          correct_index = k;
      }
      if(max == correct_index)                                               // if the network was correct, increase count of correct
      {
        correct++;
      }
    }

    for(int i = 0; i < num_categories; i++)
      printf("actual: %f expected: %f\n", output_layer[i].value, expected_output_layer[i].value);
    correct = correct / training_set_size * 100;                           // convert total correct to percentage
    printf("training set accuracy: %f %%\n", correct);
    correct = 0;

//    if(i > VALIDATION_THRESHOLD)                                 // if more than validation_threshold epochs have passed and its a multiple of 5
    {
      for(int j = training_set_size; j < training_set_size + validation_set_size; j++)         // run validation on network
      {
        char expected_output =                                                     // store expected output for this doc
             file_names_array[file_names_index[j]][strlen(directory)];
        for(int k = 0; k < num_categories; k++)
        {
          if(expected_output_layer[k].tag[0] == expected_output)
            expected_output_layer[k].value = 1;
          else
            expected_output_layer[k].value = 0;
        }

        for(int k = 0; k < num_categories * 50; k++)                               // set input value for each word count for this doc
        {
          input_layer[k].value = input_values[j][k];
        }

        // run NNIDT
        forward_propagate(input_layer, literal_layer, num_categories * 50, num_literals);
        forward_propagate(literal_layer, conjunctive_layer, num_literals, num_conjuncts);
        forward_propagate(conjunctive_layer, output_layer, num_conjuncts, num_categories);

        int max = 0;
        int correct_index;
        for(int k = 0; k < num_categories; k++)                                // compute if the network got this one correct
        {
          if(output_layer[k].value > output_layer[max].value)
            max = k;
        }
        for(int k = 0; k < num_categories; k++)
        {
          if(expected_output_layer[k].value == 1)
            correct_index = k;
        }
        if(max == correct_index)                                               // if the network was correct, increase count of correct
        {
          correct++;
        }
      }
      correct = correct / validation_set_size * 100;                           // convert total correct to percentage
      printf("validation set accuracy: %f %%, previous best: %f %%\n", correct, previous_best);
      if(correct >= previous_best)                                              // if this accuracy is higher than the previous
      {
        previous_best = correct;                                               // make this the previous best
      }  
      else if(previous_best >= 80)
      {
        input_layer = previous_input;                                          // reset network to previous best
        literal_layer = previous_literal;
        conjunctive_layer = previous_conjunctive;
        output_layer = previous_output;
        completed_epochs = i;
        stop = 1;
      }
      correct = 0;
    }
//    DoProgress("training NNIDT: ", i+1, EPOCHS);                               // print progress of training
  }
  printf("\n");
  printf("completed training epochs: %d\n", completed_epochs);
  printf("validation accuracy: %f\n", previous_best);
  if(output_layer[0].value != output_layer[0].value)
    fprintf(test_results, "yes,");
  else fprintf(test_results, "no,");
  fprintf(test_results, "%d,", completed_epochs);
//  fprintf(test_results, "%f, ", previous_best);
  for(int i = 0; i < num_conjuncts; i++)
  {
    for(int j = 0; j < num_categories; j++)
      printf("%f\n", conjunctive_layer[i].weights[j]);
  }

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
    int correct_index = 0;
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
//    int all_in_range = 1;
  printf("correctly categorized documents during testing: %f %%\n\n", correct); // print percent correct during testing
  fprintf(test_results, "%f\n", correct);

//  fclose(test_results);
  //random_init_nn(num_categories * 50, num_categories, num_literals, num_conjuncts, LR, training_size, sample_size); // run rinn on same training set
  fclose(sample_output);                                                       // close sample_output file for rinn to use
}
fclose(test_results);
free(test_results);
  return 0;
}

/*
  return result of sigmoid funciton on x
*/
double sigmoid(double x)
{
  double e = exp((double)-x);
  if(1+e == 0)
    printf("divide by zero\n");
  return (double)1/(1 + e);
}

/*
  return the result of the derivative of the sigmoid function with regards to x
*/
double sigmoid_derivative(double x)
{
  double e = sigmoid((double)x);
  return (double)e * (1 - e);
}

/*
  compute activation in right_layer based on left_layer
*/
void forward_propagate(Node *left_layer, Node *right_layer, int num_left, int num_right)
{
  for(int i = 0; i < num_right; i++)
  {
    double sum = 0;
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
void compute_error_for_output(Node *actual, Node *expected, int num_output, double lr)
{
  for(int i = 0; i < num_output; i++)
  {
    double roc = actual[i].value - expected[i].value;                           // compute the rate of change of the cost function
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
void adjust_weights(Node *left_layer, Node *right_layer, int num_left, int num_right, double lr)
{
  for(int i = 0; i < num_left; i++)
  {
    for(int j = 0; j < num_right; j++)
    {
      double change_to_cost_func = left_layer[i].value * right_layer[j].error;  // calculate change to the cost function my multiplying this nodes value by the next layers nodes error
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
