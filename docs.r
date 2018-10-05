
C4.5 [release 8] rule generator	Thu Oct  4 23:20:55 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 65:
    	tory > 0
	->  class p  [96.1%]

Rule 54:
    	tories > 0
	->  class p  [95.8%]

Rule 56:
    	commons > 0
	->  class p  [93.3%]

Rule 57:
    	immigration > 0
	->  class p  [93.3%]

Rule 31:
    	conservatives > 0
	->  class p  [93.0%]

Rule 32:
    	mps > 1
	->  class p  [90.6%]

Rule 33:
    	prices <= 0
    	economy <= 0
    	firms <= 0
    	market <= 0
    	foreign > 0
    	film <= 0
	->  class p  [90.6%]

Rule 10:
    	manifesto > 0
	->  class p  [85.7%]

Rule 12:
    	lords > 2
	->  class p  [82.0%]

Rule 11:
    	drinking > 2
	->  class p  [50.0%]

Rule 21:
    	chelsea > 0
	->  class s  [91.7%]

Rule 27:
    	slam > 0
	->  class s  [91.2%]

Rule 28:
    	scored > 0
	->  class s  [91.2%]

Rule 6:
    	champions > 0
	->  class s  [90.6%]

Rule 22:
    	championships > 0
	->  class s  [90.6%]

Rule 5:
    	finals > 0
	->  class s  [88.2%]

Rule 7:
    	arsenal > 0
	->  class s  [88.2%]

Rule 20:
    	flanker > 0
	->  class s  [88.2%]

Rule 3:
    	charlton > 0
	->  class s  [75.8%]

Rule 4:
    	thanou > 1
	->  class s  [70.7%]

Rule 64:
    	web > 0
	->  class t  [94.2%]

Rule 63:
    	device > 0
	->  class t  [92.2%]

Rule 17:
    	technologies > 0
	->  class t  [91.7%]

Rule 35:
    	phones > 0
	->  class t  [89.9%]

Rule 25:
    	windows > 0
	->  class t  [89.1%]

Rule 37:
    	programs > 0
	->  class t  [89.1%]

Rule 36:
    	spam > 0
	->  class t  [87.1%]

Rule 26:
    	film <= 0
    	movie > 0
	->  class t  [85.7%]

Rule 62:
    	xbox > 0
	->  class t  [75.8%]

Rule 61:
    	film > 1
    	device <= 0
	->  class e  [92.0%]

Rule 16:
    	bn <= 0
    	comedy > 0
	->  class e  [91.7%]

Rule 58:
    	singer > 0
    	device <= 0
	->  class e  [91.2%]

Rule 55:
    	album > 0
    	device <= 0
	->  class e  [89.9%]

Rule 30:
    	drama > 0
	->  class e  [79.4%]

Rule 15:
    	musical > 1
	->  class e  [75.8%]

Rule 41:
    	bn <= 0
    	band > 0
    	tories <= 0
	->  class e  [75.6%]

Rule 14:
    	concert > 1
	->  class e  [63.0%]

Rule 44:
    	prices > 0
    	film <= 0
    	web <= 0
    	device <= 0
	->  class b  [95.2%]

Rule 43:
    	economy > 0
    	tory <= 0
    	tories <= 0
    	web <= 0
	->  class b  [95.0%]

Rule 42:
    	shares > 0
    	web <= 0
	->  class b  [91.2%]

Rule 13:
    	exports > 0
	->  class b  [91.2%]

Rule 53:
    	bn > 0
    	film <= 0
    	tory <= 0
    	tories <= 0
    	web <= 0
    	device <= 0
	->  class b  [89.1%]

Rule 39:
    	market > 0
    	food > 0
	->  class b  [85.7%]

Rule 40:
    	investors > 1
	->  class b  [85.7%]

Default class: s


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  65     1   3.9%    35      0 (0.0%)	     5 (5|0) 	p
  54     1   4.2%     9      0 (0.0%)	     5 (5|0) 	p
  56     1   6.7%    10      0 (0.0%)	     3 (3|0) 	p
  57     1   6.7%     7      0 (0.0%)	     2 (2|0) 	p
  31     1   7.0%     4      0 (0.0%)	     4 (4|0) 	p
  32     1   9.4%     4      0 (0.0%)	     4 (4|0) 	p
  33     6   9.4%     7      0 (0.0%)	     7 (7|0) 	p
  10     1  14.3%     2      0 (0.0%)	     2 (2|0) 	p
  12     1  18.0%     2      0 (0.0%)	     2 (2|0) 	p
  11     1  50.0%     2      0 (0.0%)	     2 (2|0) 	p
  21     1   8.3%    16      0 (0.0%)	     0 (0|0) 	s
  27     1   8.8%    15      0 (0.0%)	     0 (0|0) 	s
  28     1   8.8%    11      0 (0.0%)	     0 (0|0) 	s
   6     1   9.4%     5      0 (0.0%)	     0 (0|0) 	s
  22     1   9.4%    13      0 (0.0%)	     0 (0|0) 	s
   5     1  11.8%     3      0 (0.0%)	     0 (0|0) 	s
   7     1  11.8%     3      0 (0.0%)	     0 (0|0) 	s
  20     1  11.8%     5      0 (0.0%)	     0 (0|0) 	s
   3     1  24.2%     3      0 (0.0%)	     0 (0|0) 	s
   4     1  29.3%     3      0 (0.0%)	     0 (0|0) 	s
  64     1   5.8%    23      0 (0.0%)	    10 (10|0) 	t
  63     1   7.8%    14      0 (0.0%)	     4 (4|0) 	t
  17     1   8.3%     7      0 (0.0%)	     5 (5|0) 	t
  35     1  10.1%     7      0 (0.0%)	     5 (5|0) 	t
  25     1  10.9%     5      0 (0.0%)	     4 (4|0) 	t
  37     1  10.9%     5      0 (0.0%)	     3 (3|0) 	t
  36     1  12.9%     5      0 (0.0%)	     5 (5|0) 	t
  26     2  14.3%     4      0 (0.0%)	     4 (4|0) 	t
  62     1  24.2%     3      0 (0.0%)	     3 (3|0) 	t
  61     2   8.0%    32      1 (3.1%)	    15 (15|0) 	e
  16     2   8.3%     5      0 (0.0%)	     4 (4|0) 	e
  58     2   8.8%    11      0 (0.0%)	     5 (5|0) 	e
  55     2  10.1%     7      0 (0.0%)	     4 (4|0) 	e
  30     1  20.6%     4      0 (0.0%)	     4 (4|0) 	e
  15     1  24.2%     3      0 (0.0%)	     3 (3|0) 	e
  41     3  24.4%     4      0 (0.0%)	     4 (4|0) 	e
  14     1  37.0%     2      0 (0.0%)	     2 (2|0) 	e
  44     4   4.8%    28      0 (0.0%)	     8 (8|0) 	b
  43     4   5.0%    13      0 (0.0%)	     5 (5|0) 	b
  42     2   8.8%    25      1 (4.0%)	     9 (9|0) 	b
  13     1   8.8%     5      0 (0.0%)	     4 (4|0) 	b
  53     6  10.9%    22      3 (13.6%)	    17 (17|0) 	b
  39     2  14.3%     2      0 (0.0%)	     2 (2|0) 	b
  40     1  14.3%     2      0 (0.0%)	     2 (2|0) 	b

Tested 496, errors 66 (13.3%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   93             17     	(a): class b
	    1   67        11     	(b): class e
	    2        82   15     	(c): class p
	                 115     	(d): class s
	    1    1        18   73	(e): class t

