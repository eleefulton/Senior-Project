
C4.5 [release 8] rule generator	Fri Sep 21 16:49:07 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 28:
    	chelsea > 0
	->  class s  [93.0%]

Rule 3:
    	rugby > 0
	->  class s  [91.2%]

Rule 23:
    	championships > 0
	->  class s  [91.2%]

Rule 4:
    	arsenal > 0
	->  class s  [90.6%]

Rule 21:
    	matches > 0
	->  class s  [89.1%]

Rule 22:
    	scrum > 0
	->  class s  [88.2%]

Rule 20:
    	tournament > 0
	->  class s  [87.1%]

Rule 11:
    	gerrard > 0
	->  class s  [79.4%]

Rule 6:
    	hewitt > 0
	->  class s  [75.8%]

Rule 10:
    	ulster > 0
	->  class s  [75.8%]

Rule 9:
    	uefa > 0
	->  class s  [70.7%]

Rule 7:
    	rangers > 1
	->  class s  [63.0%]

Rule 61:
    	users > 0
	->  class t  [96.1%]

Rule 60:
    	devices > 0
	->  class t  [92.6%]

Rule 52:
    	technologies > 0
	->  class t  [90.6%]

Rule 36:
    	developers > 0
	->  class t  [88.2%]

Rule 51:
    	mobiles > 0
	->  class t  [88.2%]

Rule 15:
    	xbox > 0
	->  class t  [85.7%]

Rule 14:
    	messages > 1
	->  class t  [63.0%]

Rule 44:
    	band > 0
    	tory <= 0
    	tories <= 0
    	users <= 0
    	technologies <= 0
	->  class e  [94.2%]

Rule 41:
    	comedy > 0
    	users <= 0
	->  class e  [90.6%]

Rule 42:
    	actress > 0
	->  class e  [90.6%]

Rule 40:
    	viewers > 0
    	technologies <= 0
	->  class e  [89.1%]

Rule 39:
    	singer > 0
    	devices <= 0
	->  class e  [88.5%]

Rule 17:
    	chart > 0
    	developers <= 0
	->  class e  [88.2%]

Rule 18:
    	festival > 1
	->  class e  [82.0%]

Rule 59:
    	tories > 0
	->  class p  [95.2%]

Rule 45:
    	tory > 0
    	liberal <= 0
	->  class p  [91.2%]

Rule 26:
    	bn <= 0
    	immigration > 0
	->  class p  [89.9%]

Rule 46:
    	liberal > 0
	->  class p  [89.8%]

Rule 13:
    	lib > 0
	->  class p  [86.7%]

Rule 43:
    	lords > 0
	->  class p  [85.7%]

Rule 34:
    	assembly > 0
    	developers <= 0
	->  class p  [82.0%]

Rule 58:
    	straw > 0
	->  class p  [82.0%]

Rule 35:
    	muslim > 1
	->  class p  [70.7%]

Rule 50:
    	stock > 0
	->  class b  [95.2%]

Rule 27:
    	revenues > 0
    	users <= 0
	->  class b  [91.2%]

Rule 48:
    	shares > 0
    	tories <= 0
	->  class b  [90.5%]

Rule 19:
    	output > 0
    	band <= 0
	->  class b  [89.1%]

Rule 57:
    	bn > 0
    	tories <= 0
    	straw <= 0
	->  class b  [88.0%]

Rule 49:
    	prices > 0
    	users <= 0
    	devices <= 0
	->  class b  [85.1%]

Rule 47:
    	economic > 0
    	prices <= 0
    	tories <= 0
    	users <= 0
	->  class b  [81.2%]

Default class: s


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  28     1   7.0%    19      0 (0.0%)	     0 (0|0) 	s
   3     1   8.8%    15      0 (0.0%)	     0 (0|0) 	s
  23     1   8.8%    14      0 (0.0%)	     0 (0|0) 	s
   4     1   9.4%     6      0 (0.0%)	     0 (0|0) 	s
  21     1  10.9%     5      0 (0.0%)	     0 (0|0) 	s
  22     1  11.8%     4      0 (0.0%)	     0 (0|0) 	s
  20     1  12.9%     6      0 (0.0%)	     0 (0|0) 	s
  11     1  20.6%     2      0 (0.0%)	     0 (0|0) 	s
   6     1  24.2%     2      0 (0.0%)	     0 (0|0) 	s
  10     1  24.2%     2      0 (0.0%)	     0 (0|0) 	s
   9     1  29.3%     3      0 (0.0%)	     0 (0|0) 	s
   7     1  37.0%     2      0 (0.0%)	     0 (0|0) 	s
  61     1   3.9%    35      0 (0.0%)	    24 (24|0) 	t
  60     1   7.4%    12      0 (0.0%)	     4 (4|0) 	t
  52     1   9.4%     7      0 (0.0%)	     4 (4|0) 	t
  36     1  11.8%     4      0 (0.0%)	     3 (3|0) 	t
  51     1  11.8%     7      0 (0.0%)	     7 (7|0) 	t
  15     1  14.3%     2      0 (0.0%)	     2 (2|0) 	t
  14     1  37.0%     2      0 (0.0%)	     2 (2|0) 	t
  44     5   5.8%    23      0 (0.0%)	     5 (5|0) 	e
  41     2   9.4%    12      0 (0.0%)	     4 (4|0) 	e
  42     1   9.4%    10      0 (0.0%)	     8 (8|0) 	e
  40     2  10.9%     6      0 (0.0%)	     6 (6|0) 	e
  39     2  11.5%     8      1 (12.5%)	     7 (7|0) 	e
  17     2  11.8%     2      0 (0.0%)	     2 (2|0) 	e
  18     1  18.0%     4      0 (0.0%)	     4 (4|0) 	e
  59     1   4.8%    28      0 (0.0%)	     2 (2|0) 	p
  45     2   8.8%     7      0 (0.0%)	     5 (5|0) 	p
  26     2  10.1%     3      0 (0.0%)	     3 (3|0) 	p
  46     1  10.2%    14      1 (7.1%)	    10 (10|0) 	p
  13     1  13.3%     2      0 (0.0%)	     2 (2|0) 	p
  43     1  14.3%     5      0 (0.0%)	     4 (4|0) 	p
  34     2  18.0%     4      0 (0.0%)	     4 (4|0) 	p
  58     1  18.0%     4      0 (0.0%)	     4 (4|0) 	p
  35     1  29.3%     4      0 (0.0%)	     4 (4|0) 	p
  50     1   4.8%    28      0 (0.0%)	     2 (2|0) 	b
  27     2   8.8%    12      0 (0.0%)	     3 (3|0) 	b
  48     2   9.5%    22      2 (9.1%)	     6 (6|0) 	b
  19     2  10.9%     9      0 (0.0%)	     4 (4|0) 	b
  57     3  12.0%    29      3 (10.3%)	    17 (17|0) 	b
  49     3  14.9%    11      1 (9.1%)	    10 (10|0) 	b
  47     4  18.8%    11      3 (27.3%)	     8 (8|0) 	b

Tested 496, errors 70 (14.1%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  113         1    6     	(a): class b
	    3   64        17     	(b): class e
	    4    1   70   18     	(c): class p
	                 110     	(d): class s
	    2             18   69	(e): class t

