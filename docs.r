
C4.5 [release 8] rule generator	Fri Nov  2 15:47:21 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 338's class of '0' is illegal

Read 338 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 21:
    	music > 0
    	mp <= 0
    	user <= 0
    	web <= 0
    	machin <= 0
    	without <= 0
	->  class e  [93.6%]

Rule 28:
    	singer > 0
    	mp <= 0
	->  class e  [91.7%]

Rule 23:
    	movi > 0
    	user <= 0
    	machin <= 0
    	gamer <= 0
	->  class e  [90.6%]

Rule 27:
    	oscar > 0
	->  class e  [90.6%]

Rule 34:
    	tori > 0
	->  class p  [95.9%]

Rule 30:
    	music <= 1
    	mp > 0
    	machin <= 0
	->  class p  [95.2%]

Rule 32:
    	oppos > 0
	->  class p  [89.1%]

Rule 26:
    	inquiri > 0
	->  class p  [82.0%]

Rule 7:
    	opportun > 1
    	user <= 0
	->  class p  [63.0%]

Rule 12:
    	champion > 0
    	engin <= 0
	->  class s  [95.0%]

Rule 3:
    	cup > 0
	->  class s  [94.4%]

Rule 35:
    	user > 0
	->  class t  [95.6%]

Rule 25:
    	web > 0
	->  class t  [91.2%]

Rule 19:
    	engin > 0
	->  class t  [89.9%]

Rule 33:
    	machin > 0
	->  class t  [89.1%]

Rule 24:
    	gamer > 0
	->  class t  [79.4%]

Rule 31:
    	music > 1
    	mp > 0
	->  class t  [63.0%]

Rule 29:
    	growth > 0
    	mp <= 0
    	user <= 0
	->  class b  [94.6%]

Rule 10:
    	bank > 1
	->  class b  [87.1%]

Rule 15:
    	price > 0
    	mp <= 0
    	phone <= 0
    	user <= 0
    	machin <= 0
	->  class b  [83.8%]

Rule 14:
    	sharehold > 0
	->  class b  [82.2%]

Rule 9:
    	telegraph > 0
	->  class b  [50.0%]

Default class: s


Evaluation on training data (338 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  21     6   6.4%    21      0 (0.0%)	    10 (10|0) 	e
  28     2   8.3%     8      0 (0.0%)	     7 (7|0) 	e
  23     4   9.4%    11      0 (0.0%)	     6 (6|0) 	e
  27     1   9.4%     7      0 (0.0%)	     7 (7|0) 	e
  34     1   4.1%    33      0 (0.0%)	    15 (15|0) 	p
  30     3   4.8%    11      0 (0.0%)	     8 (8|0) 	p
  32     1  10.9%     6      0 (0.0%)	     5 (5|0) 	p
  26     1  18.0%     4      0 (0.0%)	     4 (4|0) 	p
   7     2  37.0%     2      0 (0.0%)	     2 (2|0) 	p
  12     2   5.0%    27      0 (0.0%)	     1 (1|0) 	s
   3     1   5.6%    18      0 (0.0%)	     0 (0|0) 	s
  35     1   4.4%    31      0 (0.0%)	    17 (17|0) 	t
  25     1   8.8%     6      0 (0.0%)	     3 (3|0) 	t
  19     1  10.1%     3      0 (0.0%)	     3 (3|0) 	t
  33     1  10.9%     7      0 (0.0%)	     5 (5|0) 	t
  24     1  20.6%     4      0 (0.0%)	     4 (4|0) 	t
  31     2  37.0%     3      0 (0.0%)	     3 (3|0) 	t
  29     3   5.4%    25      0 (0.0%)	    13 (13|0) 	b
  10     1  12.9%     4      0 (0.0%)	     2 (2|0) 	b
  15     5  16.2%    14      2 (14.3%)	    11 (11|0) 	b
  14     1  17.8%    11      0 (0.0%)	    11 (11|0) 	b
   9     1  50.0%     2      0 (0.0%)	     2 (2|0) 	b

Tested 338, errors 47 (13.9%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   54             17     	(a): class b
	    1   47        10     	(b): class e
	    1        56    9     	(c): class p
	                  80     	(d): class s
	                   9   54	(e): class t

