# tfidf
tf-idf tool

Program Description:
  This program computes TF-IDF for words in a category of documents by computing term frequency
  across all documents in a category (number of times word appears in category divided by number of total
  length of category measured in words), then multiplying that by the natural log of the inverse category 
  frequency of the word (total number of categories divided by number of categories that word appears in).
  
How to Compile:
```
$ make
```

How to Run:
```
$ ./tfidf /path/to/files/ number_of_categories category_prefix number_of_docs_in_category ...
```

Input format:
  The first command line argument is the directory in which the training files are located.
  The second command line argument is how many categories there are to be compared (max 5).
  The next n arguments are the prefix for the category and the number of documents in that
  category. Files should be named with the prefix followed by a three digit number.

Example File Names for business category with two files: 'b001.txt' 'b002.txt' ...

Example Input:
```
$ ./tfidf ./path/to/files/ 2 b 5 e 7
```

Output:
  Output will be stored in the /50_words folder. A seperate .out file will be created for each category
  that will list the 50-most-important-words for that category along with a single file that combines all
  50-words from each category in the order the categories were given and a .names file for use with
  the C4.5 decision tree..


BBC Dataset: http://mlg.ucd.ie/datasets/bbc.html
