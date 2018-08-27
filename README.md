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
<<<<<<< HEAD
  Output will be formatted as a list of each category and it's assiciated 50-most-important-words,
  and each word's tfidf.

Example Output:
 num categories: 2
  b: 2
  e: 2
  [b]
  timewarner, 0.005961
  aol, 0.005961
  dollar, 0.005109
  deficit, 0.005109
  time, 0.004258
  profit, 0.004258
  profits, 0.004258
  bn, 0.004258
  ...
=======
  Output will be formatted as n categories and how many documents are in each, followed by 
  a list of m words and their tf-idf for each category.
  
Example Output:
```
num categories: n
category 0 prefix: num docs in category
...
category n-1 prefix: num docs in category
word0: [tf category 0]...[tf category n-1] idf: x
...
wordm-1: [tf category 0]...[tf category n-1] idf: x
```
>>>>>>> 89bbe681b2a412eafb0ffd29a1157660eb74da0a
