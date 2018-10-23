
C4.5 [release 8] rule generator	Tue Oct 23 00:28:47 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 338's class of '0' is illegal

Read 338 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 13:
    	cup > 0
	->  class s  [92.6%]

Rule 16:
    	championship > 0
	->  class s  [92.2%]

Rule 8:
    	arsen > 0
	->  class s  [88.2%]

Rule 15:
    	striker > 0
	->  class s  [85.7%]

Rule 10:
    	driscol > 0
	->  class s  [82.0%]

Rule 11:
    	phillip > 0
	->  class s  [75.8%]

Rule 55:
    	softwar > 0
	->  class t  [94.2%]

Rule 54:
    	web > 0
	->  class t  [93.3%]

Rule 49:
    	devic > 0
	->  class t  [90.6%]

Rule 20:
    	handset > 0
	->  class t  [85.7%]

Rule 21:
    	gadget > 0
	->  class t  [85.7%]

Rule 47:
    	analyst > 0
    	chart > 0
	->  class t  [63.0%]

Rule 40:
    	analyst <= 0
    	music > 0
    	unit <= 0
    	softwar <= 0
    	devic <= 0
	->  class e  [90.9%]

Rule 37:
    	comedi > 0
	->  class e  [90.6%]

Rule 38:
    	actress > 0
	->  class e  [89.9%]

Rule 39:
    	oscar > 0
	->  class e  [89.9%]

Rule 34:
    	boi > 0
	->  class e  [80.9%]

Rule 56:
    	tori > 0
	->  class p  [95.8%]

Rule 33:
    	product <= 0
    	shadow > 0
	->  class p  [92.2%]

Rule 26:
    	blair > 0
	->  class p  [90.9%]

Rule 30:
    	manifesto > 0
	->  class p  [87.1%]

Rule 29:
    	ukip > 0
	->  class p  [75.8%]

Rule 28:
    	goldsmith > 0
	->  class p  [70.7%]

Rule 19:
    	strike > 0
	->  class p  [50.0%]

Rule 53:
    	bn > 1
    	tori <= 0
    	softwar <= 0
    	web <= 0
	->  class b  [94.6%]

Rule 46:
    	economi > 1
    	tori <= 0
	->  class b  [89.9%]

Rule 44:
    	analyst > 0
    	chart <= 0
    	softwar <= 0
    	web <= 0
	->  class b  [86.6%]

Rule 42:
    	oil > 0
	->  class b  [86.0%]

Rule 31:
    	economist > 0
	->  class b  [82.2%]

Default class: s


Evaluation on training data (338 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  13     1   7.4%    18      0 (0.0%)	     0 (0|0) 	s
  16     1   7.8%    14      0 (0.0%)	     0 (0|0) 	s
   8     1  11.8%     8      0 (0.0%)	     1 (1|0) 	s
  15     1  14.3%     2      0 (0.0%)	     0 (0|0) 	s
  10     1  18.0%     4      0 (0.0%)	     0 (0|0) 	s
  11     1  24.2%     3      0 (0.0%)	     0 (0|0) 	s
  55     1   5.8%    23      0 (0.0%)	    10 (10|0) 	t
  54     1   6.7%    11      0 (0.0%)	     8 (8|0) 	t
  49     1   9.4%     6      0 (0.0%)	     2 (2|0) 	t
  20     1  14.3%     4      0 (0.0%)	     4 (4|0) 	t
  21     1  14.3%     2      0 (0.0%)	     2 (2|0) 	t
  47     2  37.0%     3      0 (0.0%)	     3 (3|0) 	t
  40     5   9.1%    27      0 (0.0%)	    15 (15|0) 	e
  37     1   9.4%     9      0 (0.0%)	     4 (4|0) 	e
  38     1  10.1%     7      0 (0.0%)	     3 (3|0) 	e
  39     1  10.1%     3      0 (0.0%)	     3 (3|0) 	e
  34     1  19.1%     3      0 (0.0%)	     3 (3|0) 	e
  56     1   4.2%    32      0 (0.0%)	    11 (11|0) 	p
  33     2   7.8%     8      0 (0.0%)	     5 (5|0) 	p
  26     1   9.1%     8      1 (12.5%)	     3 (4|1) 	p
  30     1  12.9%     4      0 (0.0%)	     3 (3|0) 	p
  29     1  24.2%     3      0 (0.0%)	     3 (3|0) 	p
  28     1  29.3%     3      0 (0.0%)	     3 (3|0) 	p
  19     1  50.0%     2      0 (0.0%)	     2 (2|0) 	p
  53     4   5.4%    25      0 (0.0%)	    12 (12|0) 	b
  46     2  10.1%    12      0 (0.0%)	     2 (2|0) 	b
  44     4  13.4%    13      1 (7.7%)	    11 (11|0) 	b
  42     1  14.0%     6      0 (0.0%)	     6 (6|0) 	b
  31     1  17.8%     2      0 (0.0%)	     2 (2|0) 	b

Tested 338, errors 51 (15.1%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   57             10     	(a): class b
	        49        11     	(b): class e
	             59   16     	(c): class p
	              1   73     	(d): class s
	    1             12   49	(e): class t

