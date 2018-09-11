
C4.5 [release 8] rule generator	Tue Sep 11 13:20:27 2018
-------------------------------

    Options:
	File stem <./50_words/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./50_words/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 54:
    	tory > 0
	->  class p  [96.0%]

Rule 51:
    	tories > 0
	->  class p  [95.3%]

Rule 50:
    	commons > 0
	->  class p  [92.6%]

Rule 32:
    	constituency > 0
	->  class p  [88.2%]

Rule 21:
    	clarke > 1
	->  class p  [84.1%]

Rule 44:
    	software > 0
	->  class t  [95.5%]

Rule 41:
    	broadband > 0
	->  class t  [94.2%]

Rule 40:
    	technologies > 0
	->  class t  [92.6%]

Rule 26:
    	apple > 0
	->  class t  [91.7%]

Rule 37:
    	xbox > 0
	->  class t  [89.9%]

Rule 38:
    	computers > 0
	->  class t  [89.1%]

Rule 39:
    	portable > 0
	->  class t  [89.1%]

Rule 24:
    	google > 0
	->  class t  [88.2%]

Rule 25:
    	multimedia > 0
	->  class t  [85.7%]

Rule 17:
    	laptops > 0
	->  class t  [79.4%]

Rule 31:
    	bank > 0
    	actor <= 0
    	tories <= 0
    	commons <= 0
    	portable <= 0
    	computers <= 0
	->  class b  [96.7%]

Rule 18:
    	stock > 0
    	actor <= 0
    	software <= 0
	->  class b  [94.2%]

Rule 29:
    	oil > 0
    	software <= 0
	->  class b  [94.2%]

Rule 8:
    	profits > 0
    	multimedia <= 0
	->  class b  [92.2%]

Rule 4:
    	economic > 0
    	tories <= 0
    	tory <= 0
    	portable <= 0
	->  class b  [92.0%]

Rule 19:
    	earnings > 0
	->  class b  [87.1%]

Rule 6:
    	takeover > 0
	->  class b  [82.0%]

Rule 7:
    	airline > 0
    	analysts <= 0
	->  class b  [79.4%]

Rule 5:
    	corp > 0
	->  class b  [75.8%]

Rule 49:
    	coach > 0
	->  class s  [96.0%]

Rule 47:
    	arsenal > 0
	->  class s  [91.2%]

Rule 48:
    	finals > 0
	->  class s  [91.2%]

Rule 46:
    	ball > 0
	->  class s  [90.6%]

Rule 45:
    	champion > 0
	->  class s  [89.0%]

Rule 28:
    	seed > 0
	->  class s  [88.2%]

Rule 30:
    	rugby > 1
	->  class s  [87.1%]

Rule 33:
    	champions > 0
	->  class s  [85.2%]

Rule 16:
    	indoor > 0
	->  class s  [84.1%]

Rule 27:
    	villa > 0
	->  class s  [75.8%]

Rule 15:
    	rusedski > 0
	->  class s  [70.7%]

Rule 53:
    	actor > 0
	->  class e  [93.6%]

Rule 14:
    	actress > 0
	->  class e  [93.3%]

Rule 36:
    	chart > 0
    	xbox <= 0
	->  class e  [89.9%]

Rule 34:
    	awards > 0
	->  class e  [89.8%]

Rule 43:
    	starring > 0
	->  class e  [89.1%]

Rule 52:
    	singer > 0
	->  class e  [89.0%]

Rule 35:
    	movie > 0
    	software <= 0
    	portable <= 0
	->  class e  [86.7%]

Rule 42:
    	singer <= 0
    	rock > 0
	->  class e  [82.0%]

Rule 13:
    	rap > 0
	->  class e  [75.8%]

Default class: p


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  54     1   4.0%    34      0 (0.0%)	     0 (0|0) 	p
  51     1   4.7%    11      0 (0.0%)	     0 (0|0) 	p
  50     1   7.4%    10      0 (0.0%)	     0 (0|0) 	p
  32     1  11.8%     5      0 (0.0%)	     0 (0|0) 	p
  21     1  15.9%     3      0 (0.0%)	     0 (0|0) 	p
  44     1   4.5%    30      0 (0.0%)	    13 (13|0) 	t
  41     1   5.8%    19      0 (0.0%)	     7 (7|0) 	t
  40     1   7.4%    10      0 (0.0%)	     6 (6|0) 	t
  26     1   8.3%     6      0 (0.0%)	     3 (3|0) 	t
  37     1  10.1%     6      0 (0.0%)	     5 (5|0) 	t
  38     1  10.9%     4      0 (0.0%)	     3 (3|0) 	t
  39     1  10.9%     5      0 (0.0%)	     4 (4|0) 	t
  24     1  11.8%     3      0 (0.0%)	     3 (3|0) 	t
  25     1  14.3%     3      0 (0.0%)	     3 (3|0) 	t
  17     1  20.6%     2      0 (0.0%)	     2 (2|0) 	t
  31     6   3.3%    41      0 (0.0%)	    10 (10|0) 	b
  18     3   5.8%    15      0 (0.0%)	     7 (7|0) 	b
  29     2   5.8%    12      0 (0.0%)	     6 (6|0) 	b
   8     2   7.8%    10      0 (0.0%)	     6 (6|0) 	b
   4     4   8.0%    10      1 (10.0%)	     7 (8|1) 	b
  19     1  12.9%     4      0 (0.0%)	     4 (4|0) 	b
   6     1  18.0%     2      0 (0.0%)	     1 (1|0) 	b
   7     2  20.6%     5      0 (0.0%)	     5 (5|0) 	b
   5     1  24.2%     2      0 (0.0%)	     2 (2|0) 	b
  49     1   4.0%    34      0 (0.0%)	    11 (11|0) 	s
  47     1   8.8%    12      0 (0.0%)	     7 (7|0) 	s
  48     1   8.8%    14      0 (0.0%)	     3 (3|0) 	s
  46     1   9.4%     8      0 (0.0%)	     7 (7|0) 	s
  45     1  11.0%     9      0 (0.0%)	     6 (6|0) 	s
  28     1  11.8%     3      0 (0.0%)	     2 (2|0) 	s
  30     1  12.9%     4      0 (0.0%)	     4 (4|0) 	s
  33     1  14.8%     6      1 (16.7%)	     5 (5|0) 	s
  16     1  15.9%     2      0 (0.0%)	     2 (2|0) 	s
  27     1  24.2%     3      0 (0.0%)	     3 (3|0) 	s
  15     1  29.3%     2      0 (0.0%)	     2 (2|0) 	s
  53     1   6.4%    21      0 (0.0%)	     1 (1|0) 	e
  14     1   6.7%     6      0 (0.0%)	     2 (2|0) 	e
  36     2  10.1%    12      0 (0.0%)	     5 (5|0) 	e
  34     1  10.2%     8      1 (12.5%)	     3 (3|0) 	e
  43     1  10.9%     2      0 (0.0%)	     1 (1|0) 	e
  52     1  11.0%     9      1 (11.1%)	     7 (8|1) 	e
  35     3  13.3%     6      1 (16.7%)	     5 (5|0) 	e
  42     2  18.0%     4      0 (0.0%)	     4 (4|0) 	e
  13     1  24.2%     2      0 (0.0%)	     2 (2|0) 	e

Tested 496, errors 51 (10.3%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  100        18          	(a): class b
	        67   11          	(b): class e
	    1    1   94          	(c): class p
	              9   96     	(d): class s
	         2    8    1   88	(e): class t

