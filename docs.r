
C4.5 [release 8] rule generator	Fri Sep 28 23:26:54 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 60:
    	users > 0
	->  class t  [96.8%]

Rule 46:
    	broadband > 0
	->  class t  [91.7%]

Rule 59:
    	portable > 0
	->  class t  [91.2%]

Rule 34:
    	technologies > 0
	->  class t  [89.9%]

Rule 48:
    	piracy > 0
	->  class t  [87.1%]

Rule 49:
    	developers > 0
	->  class t  [85.7%]

Rule 19:
    	spam > 0
	->  class t  [79.4%]

Rule 37:
    	mobiles > 2
	->  class t  [70.7%]

Rule 57:
    	tories > 0
	->  class p  [95.3%]

Rule 9:
    	tory > 1
	->  class p  [89.9%]

Rule 45:
    	mp > 0
    	ball <= 0
    	users <= 0
    	broadband <= 0
    	portable <= 0
	->  class p  [88.5%]

Rule 8:
    	lords > 0
    	campbell <= 0
	->  class p  [87.1%]

Rule 6:
    	straw > 1
	->  class p  [84.1%]

Rule 22:
    	manifesto > 0
	->  class p  [84.1%]

Rule 5:
    	blunkett > 0
	->  class p  [79.4%]

Rule 52:
    	coach > 0
	->  class s  [95.3%]

Rule 51:
    	tennis > 0
	->  class s  [89.9%]

Rule 29:
    	championships > 0
	->  class s  [88.2%]

Rule 15:
    	athletes > 0
	->  class s  [85.7%]

Rule 25:
    	defender > 0
	->  class s  [85.7%]

Rule 28:
    	finals > 0
	->  class s  [85.7%]

Rule 47:
    	athletics > 0
	->  class s  [85.7%]

Rule 50:
    	ball > 0
    	portable <= 0
	->  class s  [84.3%]

Rule 26:
    	goals > 0
	->  class s  [84.1%]

Rule 31:
    	arsenal > 0
	->  class s  [84.1%]

Rule 30:
    	ronaldo > 0
	->  class s  [82.0%]

Rule 27:
    	bn <= 0
    	profit <= 0
    	tie > 0
	->  class s  [79.4%]

Rule 13:
    	uefa > 0
	->  class s  [75.8%]

Rule 14:
    	secs > 0
	->  class s  [70.7%]

Rule 58:
    	actor > 0
	->  class e  [93.9%]

Rule 21:
    	category > 0
    	portable <= 0
	->  class e  [90.6%]

Rule 43:
    	festival > 0
	->  class e  [90.6%]

Rule 56:
    	comedy > 0
    	users <= 0
	->  class e  [90.6%]

Rule 54:
    	academy > 0
    	users <= 0
	->  class e  [89.9%]

Rule 55:
    	singer > 0
	->  class e  [87.9%]

Rule 40:
    	musical > 0
    	users <= 0
	->  class e  [87.1%]

Rule 41:
    	rapper > 0
	->  class e  [84.1%]

Rule 53:
    	chart > 0
	->  class e  [80.9%]

Rule 20:
    	guitarist > 0
	->  class e  [75.8%]

Rule 32:
    	legend > 0
	->  class e  [66.2%]

Rule 39:
    	prices > 0
    	chart <= 0
    	tories <= 0
    	users <= 0
    	portable <= 0
	->  class b  [93.9%]

Rule 42:
    	shares > 0
    	bn <= 0
	->  class b  [91.7%]

Rule 44:
    	bn > 0
    	academy <= 0
    	tories <= 0
    	users <= 0
    	piracy <= 0
    	developers <= 0
	->  class b  [89.7%]

Rule 38:
    	economic > 1
    	tories <= 0
	->  class b  [86.7%]

Rule 16:
    	bank > 3
	->  class b  [84.1%]

Rule 18:
    	flights > 0
	->  class b  [50.0%]

Default class: p


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  60     1   3.2%    42      0 (0.0%)	    19 (19|0) 	t
  46     1   8.3%     4      0 (0.0%)	     4 (4|0) 	t
  59     1   8.8%    14      0 (0.0%)	     9 (9|0) 	t
  34     1  10.1%     5      0 (0.0%)	     4 (4|0) 	t
  48     1  12.9%     5      0 (0.0%)	     5 (5|0) 	t
  49     1  14.3%     7      0 (0.0%)	     7 (7|0) 	t
  19     1  20.6%     2      0 (0.0%)	     2 (2|0) 	t
  37     1  29.3%     2      0 (0.0%)	     2 (2|0) 	t
  57     1   4.7%    29      0 (0.0%)	     0 (0|0) 	p
   9     1  10.1%     7      0 (0.0%)	     0 (0|0) 	p
  45     5  11.5%    16      0 (0.0%)	     1 (1|0) 	p
   8     2  12.9%     7      0 (0.0%)	     0 (0|0) 	p
   6     1  15.9%     3      0 (0.0%)	     0 (0|0) 	p
  22     1  15.9%     6      0 (0.0%)	     0 (0|0) 	p
   5     1  20.6%     2      0 (0.0%)	     0 (0|0) 	p
  52     1   4.7%    29      0 (0.0%)	    18 (18|0) 	s
  51     1  10.1%    12      0 (0.0%)	     7 (7|0) 	s
  29     1  11.8%     6      0 (0.0%)	     1 (1|0) 	s
  15     1  14.3%     5      0 (0.0%)	     2 (2|0) 	s
  25     1  14.3%     8      0 (0.0%)	     3 (3|0) 	s
  28     1  14.3%     5      0 (0.0%)	     2 (2|0) 	s
  47     1  14.3%     2      0 (0.0%)	     2 (2|0) 	s
  50     2  15.7%     8      1 (12.5%)	     5 (5|0) 	s
  26     1  15.9%     3      0 (0.0%)	     3 (3|0) 	s
  31     1  15.9%     4      0 (0.0%)	     4 (4|0) 	s
  30     1  18.0%     3      0 (0.0%)	     3 (3|0) 	s
  27     3  20.6%     3      0 (0.0%)	     3 (3|0) 	s
  13     1  24.2%     2      0 (0.0%)	     2 (2|0) 	s
  14     1  29.3%     2      0 (0.0%)	     2 (2|0) 	s
  58     1   6.1%    22      0 (0.0%)	     1 (1|0) 	e
  21     2   9.4%     7      0 (0.0%)	     2 (2|0) 	e
  43     1   9.4%     7      0 (0.0%)	     5 (5|0) 	e
  56     2   9.4%     9      0 (0.0%)	     5 (5|0) 	e
  54     2  10.1%     5      0 (0.0%)	     3 (3|0) 	e
  55     1  12.1%     8      0 (0.0%)	     6 (6|0) 	e
  40     2  12.9%     4      0 (0.0%)	     4 (4|0) 	e
  41     1  15.9%     7      0 (0.0%)	     3 (3|0) 	e
  53     1  19.1%     5      1 (20.0%)	     3 (3|0) 	e
  20     1  24.2%     2      0 (0.0%)	     2 (2|0) 	e
  32     1  33.8%     3      1 (33.3%)	     2 (2|0) 	e
  39     5   6.1%    22      0 (0.0%)	     9 (9|0) 	b
  42     2   8.3%    15      0 (0.0%)	    15 (15|0) 	b
  44     6  10.3%    40      3 (7.5%)	    27 (28|1) 	b
  38     2  13.3%     6      0 (0.0%)	     4 (4|0) 	b
  16     1  15.9%     2      0 (0.0%)	     2 (2|0) 	b
  18     1  50.0%     2      0 (0.0%)	     2 (2|0) 	b

Tested 496, errors 66 (13.3%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   84        23          	(a): class b
	        77    7          	(b): class e
	    2        97          	(c): class p
	         1   14   91     	(d): class s
	    1    1   16    1   81	(e): class t

