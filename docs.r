
C4.5 [release 8] rule generator	Tue Oct 30 17:41:27 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 338's class of '0' is illegal

Read 338 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 35:
    	cup > 0
	->  class s  [95.0%]

Rule 33:
    	coach > 0
	->  class s  [92.6%]

Rule 29:
    	rugby > 0
	->  class s  [90.6%]

Rule 34:
    	tournament > 0
	->  class s  [90.6%]

Rule 15:
    	grand > 0
    	computers <= 0
	->  class s  [89.1%]

Rule 32:
    	champion > 0
    	device <= 0
	->  class s  [87.1%]

Rule 31:
    	arsenal > 0
	->  class s  [85.7%]

Rule 19:
    	seed > 0
	->  class s  [84.1%]

Rule 20:
    	injury > 1
	->  class s  [84.1%]

Rule 40:
    	pc > 0
	->  class t  [91.7%]

Rule 38:
    	computers > 0
	->  class t  [88.2%]

Rule 37:
    	images > 0
	->  class t  [87.1%]

Rule 39:
    	device > 0
	->  class t  [87.1%]

Rule 22:
    	analysts > 1
    	tv > 0
	->  class t  [79.4%]

Rule 18:
    	spam > 0
	->  class t  [75.8%]

Rule 28:
    	comedy > 0
	->  class e  [91.2%]

Rule 26:
    	actor > 0
	->  class e  [89.1%]

Rule 27:
    	singer > 0
    	mp <= 0
	->  class e  [89.1%]

Rule 25:
    	ceremony > 0
    	arsenal <= 0
	->  class e  [88.2%]

Rule 30:
    	stars > 0
	->  class e  [86.7%]

Rule 24:
    	chart > 0
    	computers <= 0
	->  class e  [85.7%]

Rule 14:
    	actress > 1
	->  class e  [84.1%]

Rule 13:
    	prize > 1
    	tournament <= 0
	->  class e  [79.4%]

Rule 42:
    	tories > 0
	->  class p  [93.0%]

Rule 41:
    	liberal > 0
	->  class p  [92.2%]

Rule 36:
    	mp > 0
    	images <= 0
	->  class p  [89.1%]

Rule 23:
    	blair > 1
	->  class p  [84.3%]

Rule 17:
    	eu > 6
	->  class p  [70.7%]

Rule 12:
    	referendum > 0
	->  class p  [63.0%]

Rule 10:
    	analysts > 0
    	tv <= 0
    	tories <= 0
    	computers <= 0
    	images <= 0
	->  class b  [95.0%]

Rule 11:
    	prices > 0
    	tv <= 0
    	liberal <= 0
    	mp <= 0
    	computers <= 0
    	device <= 0
	->  class b  [94.2%]

Rule 16:
    	bn > 0
    	eu <= 6
    	ceremony <= 0
    	tories <= 0
    	liberal <= 0
    	device <= 0
    	images <= 0
	->  class b  [90.3%]

Default class: b


Evaluation on training data (338 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  35     1   5.0%    27      0 (0.0%)	    11 (11|0) 	s
  33     1   7.4%    12      0 (0.0%)	     5 (5|0) 	s
  29     1   9.4%     5      0 (0.0%)	     3 (3|0) 	s
  34     1   9.4%     7      0 (0.0%)	     1 (1|0) 	s
  15     2  10.9%     4      0 (0.0%)	     2 (2|0) 	s
  32     2  12.9%     4      0 (0.0%)	     3 (3|0) 	s
  31     1  14.3%     5      0 (0.0%)	     5 (5|0) 	s
  19     1  15.9%     3      0 (0.0%)	     3 (3|0) 	s
  20     1  15.9%     3      0 (0.0%)	     3 (3|0) 	s
  40     1   8.3%    16      0 (0.0%)	     7 (7|0) 	t
  38     1  11.8%     7      0 (0.0%)	     6 (6|0) 	t
  37     1  12.9%     7      0 (0.0%)	     6 (6|0) 	t
  39     1  12.9%     7      0 (0.0%)	     7 (7|0) 	t
  22     2  20.6%     3      0 (0.0%)	     3 (3|0) 	t
  18     1  24.2%     3      0 (0.0%)	     3 (3|0) 	t
  28     1   8.8%    15      0 (0.0%)	     4 (4|0) 	e
  26     1  10.9%     7      0 (0.0%)	     3 (3|0) 	e
  27     2  10.9%     8      0 (0.0%)	     3 (3|0) 	e
  25     2  11.8%     6      0 (0.0%)	     4 (4|0) 	e
  30     1  13.3%     7      1 (14.3%)	     5 (5|0) 	e
  24     2  14.3%     6      0 (0.0%)	     6 (6|0) 	e
  14     1  15.9%     2      0 (0.0%)	     2 (2|0) 	e
  13     2  20.6%     2      0 (0.0%)	     2 (2|0) 	e
  42     1   7.0%    19      0 (0.0%)	     9 (9|0) 	p
  41     1   7.8%    11      0 (0.0%)	     4 (4|0) 	p
  36     2  10.9%     8      0 (0.0%)	     7 (7|0) 	p
  23     1  15.7%     5      1 (20.0%)	     2 (3|1) 	p
  17     1  29.3%     2      0 (0.0%)	     2 (2|0) 	p
  12     1  37.0%     2      0 (0.0%)	     2 (2|0) 	p
  10     5   5.0%    27      0 (0.0%)	     0 (0|0) 	b
  11     6   5.8%    15      0 (0.0%)	     0 (0|0) 	b
  16     7   9.7%    32      3 (9.4%)	     0 (0|0) 	b

Tested 338, errors 42 (12.4%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   85         1          	(a): class b
	   10   52               	(b): class e
	   13        46          	(c): class p
	    5    1        70     	(d): class s
	   12                  43	(e): class t

