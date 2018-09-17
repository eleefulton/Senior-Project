
C4.5 [release 8] rule generator	Mon Sep 17 12:20:12 2018
-------------------------------

    Options:
	File stem <./50_words/docs>

ERROR:  case 496's class of '0' is illegal

Read 496 cases (250 attributes) from ./50_words/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 59:
    	tory > 0
	->  class p  [96.3%]

Rule 57:
    	tories > 0
	->  class p  [95.6%]

Rule 52:
    	commons > 0
    	developers <= 0
	->  class p  [94.6%]

Rule 33:
    	democrats > 0
	->  class p  [92.6%]

Rule 48:
    	constituency > 0
	->  class p  [87.1%]

Rule 34:
    	straw > 0
	->  class p  [84.1%]

Rule 14:
    	detainees > 0
	->  class p  [70.7%]

Rule 15:
    	prescott > 1
	->  class p  [70.7%]

Rule 19:
    	mock > 0
	->  class p  [63.0%]

Rule 56:
    	web > 0
	->  class t  [93.9%]

Rule 43:
    	websites > 0
	->  class t  [92.2%]

Rule 51:
    	devices > 0
	->  class t  [91.7%]

Rule 53:
    	developers > 0
	->  class t  [91.2%]

Rule 35:
    	images > 0
	->  class t  [89.1%]

Rule 31:
    	computers > 0
	->  class t  [87.1%]

Rule 16:
    	consoles > 0
	->  class t  [85.7%]

Rule 20:
    	chip > 0
	->  class t  [84.1%]

Rule 17:
    	coach > 0
	->  class s  [96.1%]

Rule 21:
    	cup > 0
	->  class s  [96.1%]

Rule 12:
    	championships > 0
	->  class s  [92.6%]

Rule 6:
    	champions > 0
	->  class s  [92.2%]

Rule 5:
    	injury > 1
	->  class s  [91.7%]

Rule 3:
    	champion > 0
	->  class s  [90.2%]

Rule 11:
    	striker > 0
	->  class s  [89.9%]

Rule 9:
    	slam > 0
	->  class s  [87.1%]

Rule 8:
    	athens > 0
	->  class s  [85.7%]

Rule 7:
    	arsenal > 1
	->  class s  [84.1%]

Rule 4:
    	doping > 1
	->  class s  [75.8%]

Rule 60:
    	actress > 0
	->  class e  [93.3%]

Rule 24:
    	companies <= 0
    	stars > 0
    	coach <= 0
	->  class e  [93.0%]

Rule 55:
    	oscar > 0
	->  class e  [91.2%]

Rule 54:
    	album > 0
    	web <= 0
	->  class e  [88.2%]

Rule 32:
    	actor > 0
    	developers <= 0
	->  class e  [86.7%]

Rule 58:
    	chart > 0
	->  class e  [85.7%]

Rule 18:
    	singer > 0
	->  class e  [83.3%]

Rule 23:
    	remain > 0
    	calling > 0
	->  class e  [50.0%]

Rule 45:
    	bn > 0
    	movie <= 0
    	tories <= 0
    	tory <= 0
    	commons <= 0
    	web <= 0
	->  class b  [91.7%]

Rule 40:
    	shares > 0
    	web <= 0
    	developers <= 0
	->  class b  [91.5%]

Rule 44:
    	economy > 0
    	tories <= 0
    	tory <= 0
    	mp <= 0
	->  class b  [88.6%]

Rule 28:
    	business > 1
    	developers <= 0
	->  class b  [88.2%]

Rule 26:
    	crude > 1
	->  class b  [70.7%]

Default class: b


Evaluation on training data (496 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  59     1   3.7%    37      0 (0.0%)	    11 (11|0) 	p
  57     1   4.4%    11      0 (0.0%)	     5 (5|0) 	p
  52     2   5.4%    10      0 (0.0%)	     6 (6|0) 	p
  33     1   7.4%     7      0 (0.0%)	     4 (4|0) 	p
  48     1  12.9%     4      0 (0.0%)	     4 (4|0) 	p
  34     1  15.9%     4      0 (0.0%)	     3 (3|0) 	p
  14     1  29.3%     2      0 (0.0%)	     2 (2|0) 	p
  15     1  29.3%     2      0 (0.0%)	     2 (2|0) 	p
  19     1  37.0%     3      0 (0.0%)	     3 (3|0) 	p
  56     1   6.1%    22      0 (0.0%)	     6 (6|0) 	t
  43     1   7.8%     5      0 (0.0%)	     3 (3|0) 	t
  51     1   8.3%    14      0 (0.0%)	     6 (6|0) 	t
  53     1   8.8%    10      0 (0.0%)	     7 (7|0) 	t
  35     1  10.9%     4      0 (0.0%)	     4 (4|0) 	t
  31     1  12.9%     4      0 (0.0%)	     4 (4|0) 	t
  16     1  14.3%     4      0 (0.0%)	     3 (3|0) 	t
  20     1  15.9%     3      0 (0.0%)	     3 (3|0) 	t
  17     1   3.9%    35      0 (0.0%)	    11 (11|0) 	s
  21     1   3.9%    20      0 (0.0%)	     9 (9|0) 	s
  12     1   7.4%    12      0 (0.0%)	     4 (4|0) 	s
   6     1   7.8%     5      0 (0.0%)	     4 (4|0) 	s
   5     1   8.3%     8      0 (0.0%)	     3 (3|0) 	s
   3     1   9.8%     8      1 (12.5%)	     4 (4|0) 	s
  11     1  10.1%     8      0 (0.0%)	     6 (6|0) 	s
   9     1  12.9%     1      0 (0.0%)	     1 (1|0) 	s
   8     1  14.3%     4      0 (0.0%)	     3 (3|0) 	s
   7     1  15.9%     3      0 (0.0%)	     3 (3|0) 	s
   4     1  24.2%     1      0 (0.0%)	     1 (1|0) 	s
  60     1   6.7%    20      0 (0.0%)	     4 (4|0) 	e
  24     3   7.0%     9      0 (0.0%)	     3 (3|0) 	e
  55     1   8.8%     6      0 (0.0%)	     4 (4|0) 	e
  54     2  11.8%     8      0 (0.0%)	     3 (3|0) 	e
  32     2  13.3%     5      1 (20.0%)	     4 (4|0) 	e
  58     1  14.3%     6      0 (0.0%)	     4 (4|0) 	e
  18     1  16.7%     3      1 (33.3%)	     2 (2|0) 	e
  23     2  50.0%     2      0 (0.0%)	     2 (2|0) 	e
  45     6   8.3%    60      3 (5.0%)	     0 (0|0) 	b
  40     3   8.5%    14      0 (0.0%)	     0 (0|0) 	b
  44     4  11.4%    17      1 (5.9%)	     0 (0|0) 	b
  28     2  11.8%     3      0 (0.0%)	     0 (0|0) 	b
  26     1  29.3%     4      0 (0.0%)	     0 (0|0) 	b

Tested 496, errors 70 (14.1%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  119                    	(a): class b
	    9   57               	(b): class e
	   21    2   80          	(c): class p
	   11            104     	(d): class s
	   26              1   66	(e): class t

