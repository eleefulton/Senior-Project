
C4.5 [release 8] rule generator	Mon Sep 17 18:02:18 2018
-------------------------------

    Options:
	File stem <./50_words/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./50_words/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 61:
    	tory > 0
	->  class p  [96.1%]

Rule 60:
    	tories > 0
	->  class p  [95.8%]

Rule 50:
    	liberal > 0
	->  class p  [95.2%]

Rule 59:
    	cabinet > 0
	->  class p  [92.6%]

Rule 12:
    	lib > 1
	->  class p  [89.1%]

Rule 43:
    	jack > 0
	->  class p  [87.1%]

Rule 28:
    	blunkett > 0
	->  class p  [85.7%]

Rule 58:
    	coach > 0
	->  class s  [96.3%]

Rule 44:
    	tournament > 0
	->  class s  [89.9%]

Rule 46:
    	finals > 0
	->  class s  [88.2%]

Rule 47:
    	indoor > 0
	->  class s  [87.1%]

Rule 35:
    	athletics > 0
	->  class s  [85.7%]

Rule 27:
    	hodgson > 0
	->  class s  [84.1%]

Rule 45:
    	arsenal > 0
	->  class s  [84.1%]

Rule 26:
    	gloucester > 0
	->  class s  [79.4%]

Rule 37:
    	microsoft > 0
	->  class t  [94.4%]

Rule 33:
    	device > 0
	->  class t  [91.7%]

Rule 23:
    	apple > 0
	->  class t  [91.2%]

Rule 32:
    	user > 0
	->  class t  [91.2%]

Rule 25:
    	download > 0
	->  class t  [89.9%]

Rule 24:
    	com > 0
	->  class t  [85.7%]

Rule 20:
    	spam > 1
	->  class t  [84.1%]

Rule 30:
    	fi > 0
	->  class t  [84.1%]

Rule 21:
    	speeds > 0
	->  class t  [82.0%]

Rule 22:
    	mobiles > 1
	->  class t  [79.4%]

Rule 6:
    	cell > 1
	->  class t  [63.0%]

Rule 57:
    	actor > 0
	->  class e  [92.2%]

Rule 14:
    	oscar > 0
	->  class e  [91.2%]

Rule 29:
    	musical > 0
    	device <= 0
	->  class e  [89.9%]

Rule 36:
    	comedy > 0
	->  class e  [89.9%]

Rule 42:
    	starring > 0
	->  class e  [89.9%]

Rule 56:
    	chart > 0
	->  class e  [89.9%]

Rule 49:
    	album > 0
	->  class e  [88.2%]

Rule 34:
    	awards > 0
    	arsenal <= 0
	->  class e  [85.2%]

Rule 41:
    	singer > 0
	->  class e  [85.2%]

Rule 13:
    	gogh > 0
	->  class e  [50.0%]

Rule 53:
    	oil > 0
	->  class b  [93.6%]

Rule 54:
    	shares > 0
    	tories <= 0
	->  class b  [93.2%]

Rule 51:
    	exports > 0
	->  class b  [89.1%]

Rule 40:
    	bn > 0
    	starring <= 0
    	theatre <= 0
    	tory <= 0
    	liberal <= 0
    	jack <= 0
    	equipment <= 0
	->  class b  [88.5%]

Rule 48:
    	banks > 0
	->  class b  [83.3%]

Rule 16:
    	bmw > 0
	->  class b  [50.0%]

Default class: s


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  61     1   3.9%    35      0 (0.0%)	     7 (7|0) 	p
  60     1   4.2%    13      0 (0.0%)	     4 (4|0) 	p
  50     1   4.8%     8      0 (0.0%)	     5 (5|0) 	p
  59     1   7.4%     7      0 (0.0%)	     5 (5|0) 	p
  12     1  10.9%     2      0 (0.0%)	     2 (2|0) 	p
  43     1  12.9%     5      0 (0.0%)	     5 (5|0) 	p
  28     1  14.3%     3      0 (0.0%)	     3 (3|0) 	p
  58     1   3.7%    37      0 (0.0%)	     0 (0|0) 	s
  44     1  10.1%     8      0 (0.0%)	     0 (0|0) 	s
  46     1  11.8%     8      0 (0.0%)	     0 (0|0) 	s
  47     1  12.9%     7      0 (0.0%)	     0 (0|0) 	s
  35     1  14.3%     4      0 (0.0%)	     0 (0|0) 	s
  27     1  15.9%     3      0 (0.0%)	     0 (0|0) 	s
  45     1  15.9%     8      0 (0.0%)	     0 (0|0) 	s
  26     1  20.6%     3      0 (0.0%)	     0 (0|0) 	s
  37     1   5.6%    24      0 (0.0%)	     9 (9|0) 	t
  33     1   8.3%    13      0 (0.0%)	     4 (4|0) 	t
  23     1   8.8%     8      0 (0.0%)	     4 (4|0) 	t
  32     1   8.8%     7      0 (0.0%)	     5 (5|0) 	t
  25     1  10.1%     5      0 (0.0%)	     4 (4|0) 	t
  24     1  14.3%     3      0 (0.0%)	     3 (3|0) 	t
  20     1  15.9%     4      0 (0.0%)	     4 (4|0) 	t
  30     1  15.9%     3      0 (0.0%)	     1 (1|0) 	t
  21     1  18.0%     3      0 (0.0%)	     3 (3|0) 	t
  22     1  20.6%     3      0 (0.0%)	     3 (3|0) 	t
   6     1  37.0%     2      0 (0.0%)	     2 (2|0) 	t
  57     1   7.8%    17      0 (0.0%)	     4 (4|0) 	e
  14     1   8.8%     6      0 (0.0%)	     3 (3|0) 	e
  29     2  10.1%    11      0 (0.0%)	     4 (4|0) 	e
  36     1  10.1%     7      0 (0.0%)	     5 (5|0) 	e
  42     1  10.1%     4      0 (0.0%)	     4 (4|0) 	e
  56     1  10.1%     5      0 (0.0%)	     1 (1|0) 	e
  49     1  11.8%     6      0 (0.0%)	     4 (4|0) 	e
  34     2  14.8%     4      1 (25.0%)	     3 (3|0) 	e
  41     1  14.8%     6      1 (16.7%)	     5 (5|0) 	e
  13     1  50.0%     2      0 (0.0%)	     2 (2|0) 	e
  53     1   6.4%    21      0 (0.0%)	     8 (8|0) 	b
  54     2   6.8%    33      1 (3.0%)	    15 (15|0) 	b
  51     1  10.9%     7      0 (0.0%)	     4 (4|0) 	b
  40     7  11.5%    23      2 (8.7%)	    17 (17|0) 	b
  48     1  16.7%     5      1 (20.0%)	     4 (4|0) 	b
  16     1  50.0%     2      0 (0.0%)	     2 (2|0) 	b

Tested 496, errors 88 (17.7%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   87             23     	(a): class b
	        66        13     	(b): class e
	    1    1   73   21     	(c): class p
	                 107     	(d): class s
	    3    1        25   75	(e): class t

