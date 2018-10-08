
C4.5 [release 8] rule generator	Fri Oct  5 12:58:33 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 670's class of '0' is illegal

Read 670 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 68:
    	tori > 0
	->  class p  [97.5%]

Rule 29:
    	manifesto > 0
	->  class p  [89.1%]

Rule 37:
    	straw > 0
	->  class p  [84.1%]

Rule 30:
    	prescott > 0
	->  class p  [82.0%]

Rule 12:
    	blunkett > 1
	->  class p  [75.8%]

Rule 11:
    	gallowai > 0
	->  class p  [50.0%]

Rule 13:
    	regiment > 0
	->  class p  [50.0%]

Rule 33:
    	analyst <= 0
    	econom <= 0
    	bank <= 0
    	itali > 0
	->  class s  [94.2%]

Rule 32:
    	rugbi > 0
	->  class s  [93.9%]

Rule 26:
    	chelsea > 0
	->  class s  [93.3%]

Rule 40:
    	striker > 0
	->  class s  [93.0%]

Rule 27:
    	athen > 0
	->  class s  [91.7%]

Rule 21:
    	flanker > 0
	->  class s  [90.6%]

Rule 19:
    	roddick > 0
	->  class s  [89.1%]

Rule 18:
    	seed > 1
	->  class s  [88.2%]

Rule 44:
    	dope > 0
	->  class s  [87.1%]

Rule 4:
    	ruddock > 0
	->  class s  [84.1%]

Rule 6:
    	davenport > 2
	->  class s  [79.4%]

Rule 7:
    	singer <= 0
    	leicest > 1
	->  class s  [79.4%]

Rule 16:
    	radcliff > 0
	->  class s  [75.8%]

Rule 17:
    	everton > 0
	->  class s  [75.8%]

Rule 61:
    	portabl > 0
	->  class t  [93.3%]

Rule 59:
    	actor <= 0
    	chart <= 0
    	download > 0
	->  class t  [91.5%]

Rule 56:
    	xbox > 0
	->  class t  [89.1%]

Rule 58:
    	virus > 0
	->  class t  [88.2%]

Rule 24:
    	graphic > 0
	->  class t  [87.1%]

Rule 25:
    	bt > 1
	->  class t  [87.1%]

Rule 55:
    	handset > 0
	->  class t  [84.1%]

Rule 31:
    	blogger > 0
	->  class t  [82.0%]

Rule 62:
    	oscar > 0
	->  class e  [94.6%]

Rule 67:
    	actor > 0
	->  class e  [94.6%]

Rule 41:
    	firm <= 0
    	econom <= 0
    	artist > 0
    	front <= 0
	->  class e  [93.9%]

Rule 57:
    	bn <= 0
    	comedi > 0
    	portabl <= 0
	->  class e  [92.6%]

Rule 39:
    	analyst <= 0
    	viewer > 0
	->  class e  [90.6%]

Rule 63:
    	singer > 0
	->  class e  [90.2%]

Rule 36:
    	prize > 1
	->  class e  [89.9%]

Rule 38:
    	firm <= 0
    	growth <= 0
    	movi > 0
    	portabl <= 0
	->  class e  [89.0%]

Rule 60:
    	chart > 0
    	portabl <= 0
	->  class e  [83.1%]

Rule 52:
    	growth > 0
    	econom > 0
    	tori <= 0
	->  class b  [94.8%]

Rule 47:
    	firm > 1
    	profit > 0
	->  class b  [92.6%]

Rule 64:
    	economist > 0
	->  class b  [92.6%]

Rule 48:
    	profit > 2
	->  class b  [91.2%]

Rule 65:
    	bn > 0
    	tori <= 0
    	anim <= 0
	->  class b  [90.4%]

Rule 51:
    	oil > 0
    	actor <= 0
	->  class b  [89.8%]

Rule 54:
    	analyst > 0
    	download <= 0
    	tori <= 0
    	portabl <= 0
    	xbox <= 0
    	handset <= 0
	->  class b  [89.8%]

Rule 53:
    	bank > 0
    	download <= 0
    	tori <= 0
    	portabl <= 0
    	virus <= 0
	->  class b  [87.6%]

Default class: s


Evaluation on training data (670 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  68     1   2.5%    54      0 (0.0%)	    40 (40|0) 	p
  29     1  10.9%     6      0 (0.0%)	     6 (6|0) 	p
  37     1  15.9%     6      0 (0.0%)	     6 (6|0) 	p
  30     1  18.0%     4      0 (0.0%)	     4 (4|0) 	p
  12     1  24.2%     2      0 (0.0%)	     2 (2|0) 	p
  11     1  50.0%     2      0 (0.0%)	     2 (2|0) 	p
  13     1  50.0%     2      0 (0.0%)	     2 (2|0) 	p
  33     4   5.8%    23      0 (0.0%)	     0 (0|0) 	s
  32     1   6.1%    16      0 (0.0%)	     1 (1|0) 	s
  26     1   6.7%    20      0 (0.0%)	     0 (0|0) 	s
  40     1   7.0%    10      0 (0.0%)	     0 (0|0) 	s
  27     1   8.3%    14      0 (0.0%)	     0 (0|0) 	s
  21     1   9.4%     5      0 (0.0%)	     0 (0|0) 	s
  19     1  10.9%    11      0 (0.0%)	     0 (0|0) 	s
  18     1  11.8%     6      0 (0.0%)	     0 (0|0) 	s
  44     1  12.9%     4      0 (0.0%)	     0 (0|0) 	s
   4     1  15.9%     2      0 (0.0%)	     0 (0|0) 	s
   6     1  20.6%     2      0 (0.0%)	     0 (0|0) 	s
   7     2  20.6%     3      0 (0.0%)	     0 (0|0) 	s
  16     1  24.2%     4      0 (0.0%)	     0 (0|0) 	s
  17     1  24.2%     3      0 (0.0%)	     0 (0|0) 	s
  61     1   6.7%    20      0 (0.0%)	    12 (12|0) 	t
  59     3   8.5%    26      1 (3.8%)	    16 (16|0) 	t
  56     1  10.9%     7      0 (0.0%)	     5 (5|0) 	t
  58     1  11.8%     9      0 (0.0%)	     8 (8|0) 	t
  24     1  12.9%     4      0 (0.0%)	     3 (3|0) 	t
  25     1  12.9%     5      0 (0.0%)	     5 (5|0) 	t
  55     1  15.9%     5      0 (0.0%)	     5 (5|0) 	t
  31     1  18.0%     7      0 (0.0%)	     7 (7|0) 	t
  62     1   5.4%    25      0 (0.0%)	     4 (4|0) 	e
  67     1   5.4%    11      0 (0.0%)	     2 (2|0) 	e
  41     4   6.1%    17      0 (0.0%)	     7 (7|0) 	e
  57     3   7.4%     9      0 (0.0%)	     4 (4|0) 	e
  39     2   9.4%     6      0 (0.0%)	     5 (5|0) 	e
  63     1   9.8%    11      1 (9.1%)	     4 (4|0) 	e
  36     1  10.1%     3      0 (0.0%)	     3 (3|0) 	e
  38     4  11.0%     6      1 (16.7%)	     5 (5|0) 	e
  60     2  16.9%     9      1 (11.1%)	     8 (8|0) 	e
  52     3   5.2%    26      0 (0.0%)	     3 (3|0) 	b
  47     2   7.4%    18      0 (0.0%)	     2 (2|0) 	b
  64     1   7.4%     8      0 (0.0%)	     1 (1|0) 	b
  48     1   8.8%    10      0 (0.0%)	     3 (3|0) 	b
  65     3   9.6%    52      6 (11.5%)	    18 (18|0) 	b
  51     2  10.2%     9      2 (22.2%)	     4 (4|0) 	b
  54     6  10.2%    14      2 (14.3%)	    10 (10|0) 	b
  53     5  12.4%    15      2 (13.3%)	    13 (13|0) 	b

Tested 670, errors 110 (16.4%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  140             16     	(a): class b
	        94        14    1	(b): class e
	    5    1   76   37     	(c): class p
	                 168     	(d): class s
	    7    2        27   82	(e): class t

