
C4.5 [release 8] rule generator	Mon Sep 17 22:55:30 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 59:
    	device > 0
	->  class t  [90.6%]

Rule 20:
    	images > 0
	->  class t  [89.1%]

Rule 10:
    	viruses > 0
	->  class t  [84.1%]

Rule 21:
    	programs > 0
	->  class t  [84.1%]

Rule 2:
    	spam > 0
	->  class t  [75.8%]

Rule 62:
    	singer > 0
	->  class e  [93.6%]

Rule 61:
    	nominated > 0
	->  class e  [92.2%]

Rule 60:
    	comedy > 0
	->  class e  [91.7%]

Rule 36:
    	artist > 0
	->  class e  [85.7%]

Rule 24:
    	mr <= 1
    	movie > 0
    	device <= 0
	->  class e  [85.2%]

Rule 3:
    	rapper > 0
	->  class e  [79.4%]

Rule 22:
    	mr <= 0
    	novel > 0
	->  class e  [79.4%]

Rule 11:
    	broadcasting > 0
	->  class e  [75.8%]

Rule 33:
    	festival > 1
	->  class e  [75.8%]

Rule 31:
    	bpi > 0
	->  class e  [70.7%]

Rule 13:
    	chart > 2
	->  class e  [63.0%]

Rule 50:
    	shares > 0
    	airline <= 4
	->  class b  [95.8%]

Rule 44:
    	oil > 0
	->  class b  [95.0%]

Rule 51:
    	economy > 1
    	tory <= 0
    	liberal <= 0
	->  class b  [94.2%]

Rule 43:
    	bank > 0
    	singer <= 0
    	liberal <= 0
	->  class b  [93.6%]

Rule 42:
    	investors > 0
    	government <= 0
	->  class b  [91.7%]

Rule 40:
    	bn > 0
    	government <= 0
    	movie <= 0
    	tory <= 0
    	device <= 0
	->  class b  [87.3%]

Rule 52:
    	analysts > 0
    	government > 0
    	airline <= 4
	->  class b  [87.1%]

Rule 35:
    	wto > 0
	->  class b  [70.7%]

Rule 64:
    	tory > 0
	->  class p  [95.0%]

Rule 58:
    	shadow > 0
	->  class p  [92.6%]

Rule 56:
    	government > 0
    	commons > 0
	->  class p  [89.9%]

Rule 47:
    	shares <= 0
    	analysts <= 0
    	economic <= 0
    	market <= 0
    	government > 0
    	airline <= 4
    	singer <= 0
    	nominated <= 0
    	device <= 0
	->  class p  [86.8%]

Rule 55:
    	prescott > 0
	->  class p  [63.0%]

Rule 8:
    	oil <= 0
    	shares <= 0
    	analysts <= 0
    	investors <= 0
    	bn <= 0
    	mr <= 0
    	market <= 0
    	bank <= 0
    	growth <= 0
    	government <= 0
    	singer <= 0
    	nominated <= 0
    	comedy <= 0
    	awards <= 0
    	artist <= 0
    	broadcasting <= 0
    	novel <= 0
    	singles <= 1
    	tory <= 0
    	providing <= 0
    	device <= 0
    	images <= 0
    	programs <= 0
    	viruses <= 0
	->  class s  [80.9%]

Default class: t


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  59     1   9.4%    14      0 (0.0%)	     0 (0|0) 	t
  20     1  10.9%    10      0 (0.0%)	     1 (1|0) 	t
  10     1  15.9%     8      0 (0.0%)	     0 (0|0) 	t
  21     1  15.9%     4      0 (0.0%)	     0 (0|0) 	t
   2     1  24.2%     2      0 (0.0%)	     2 (2|0) 	t
  62     1   6.4%    21      0 (0.0%)	    15 (15|0) 	e
  61     1   7.8%    16      0 (0.0%)	     9 (9|0) 	e
  60     1   8.3%    12      0 (0.0%)	     6 (6|0) 	e
  36     1  14.3%     6      0 (0.0%)	     6 (6|0) 	e
  24     3  14.8%     8      0 (0.0%)	     6 (6|0) 	e
   3     1  20.6%     4      0 (0.0%)	     4 (4|0) 	e
  22     2  20.6%     3      0 (0.0%)	     3 (3|0) 	e
  11     1  24.2%     3      0 (0.0%)	     3 (3|0) 	e
  33     1  24.2%     2      0 (0.0%)	     2 (2|0) 	e
  31     1  29.3%     4      0 (0.0%)	     2 (2|0) 	e
  13     1  37.0%     1      0 (0.0%)	     1 (1|0) 	e
  50     2   4.2%    32      0 (0.0%)	    10 (10|0) 	b
  44     1   5.0%    20      0 (0.0%)	     7 (7|0) 	b
  51     3   5.8%    16      0 (0.0%)	     9 (9|0) 	b
  43     3   6.4%    12      0 (0.0%)	     7 (7|0) 	b
  42     2   8.3%     6      0 (0.0%)	     4 (4|0) 	b
  40     5  12.7%    16      3 (18.8%)	    10 (12|2) 	b
  52     3  12.9%     4      0 (0.0%)	     4 (4|0) 	b
  35     1  29.3%     2      0 (0.0%)	     2 (2|0) 	b
  64     1   5.0%    27      0 (0.0%)	     9 (9|0) 	p
  58     1   7.4%     9      0 (0.0%)	     3 (3|0) 	p
  56     2  10.1%     5      0 (0.0%)	     2 (2|0) 	p
  47     9  13.2%    30      5 (16.7%)	    22 (23|1) 	p
  55     1  37.0%     1      0 (0.0%)	     1 (1|0) 	p
   8    24  19.1%   134     17 (12.7%)	   109 (117|8) 	s

Tested 496, errors 56 (11.3%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  105         3    3   10	(a): class b
	    1   80    1    5    7	(b): class e
	             67    1   10	(c): class p
	                 117    4	(d): class s
	    2         1    8   71	(e): class t

