# tfidf
tf-idf tool

Program Description:
  This program computes TF-IDF for words in a category of documents by computing term frequency
  across all documents in a category, then comparing the number of categories the term appears
  in.
  
Example Input:
  $./tfidf 2 b 5 e 7
  
Input format:
  The first command line argument is how many categories there are to be compared (max 5).
  The next n arguments are the prefix for the category and the number of documents in that
  category. Files should be named with the prefix followed by a three digit number.
    Example File Names for business category with two files: 'b001.txt' 'b002.txt'
