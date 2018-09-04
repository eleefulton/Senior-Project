# senior-project
Senior Research Project

Use a neural network initalized with a decisin tree to compare the classification 
method presented in “Text Categorization Using Neural Networks Initialized with 
Decision Trees” (N. Remeikis, I. Skucas, and V. Melninkaite) about categorizing 
articles into one of the following categories: business, entertainment, politics, 
sports and technology, with the method used by Justin Rebok in “Deep Belief Network 
to Classify Documents”. (1.5 person weeks over 1 semester)

Program Description
This program computes a set of 50-most important words for each category in a set of 
documents. The maximum number of categories allowed is 5. First the program computes 
TF-IDF for words in a category of documents by computing term frequency across all 
documents in a category (number of times word appears in category divided by number 
of total length of category measured in words), then multiplying that by the natural 
log of the inverse category frequency of the word (total number of categories divided 
by number of categories that word appears in). Once each unique word has an associated 
tfidf score, they are sorted and the top 50 for each category are stored into a .out 
file for each category as well as a combined .out file and builds a .names file for use
with Ross Quinlan's C4.5 decision tree. The program then reads those all 50-words from 
the combined file and stores it in an array.

Input Format
The program takes a number of command line arguments
  1. The directory in which the data files reside
  2. The number of categories
  3. n <= 5 category prefixs followed by the number of files in that category
Files in the data directory must be formatted in the following manner:
  prefix of category followed by the file's number with leading zeros.
  Example: the first file in the 'Business' category 'b001.txt'.

Example Input:
```
$./runner ./bbc_files/ 5 b 510 e 386 p 417 s 511 t 401 
```

How to Compile
```
$make
```

Program Output
This program outputs a .out file for each of the given categories and stores them in the
/50-words folder. It also creates a combined-50.out file and a categories.names file for
use with the decision tree.
