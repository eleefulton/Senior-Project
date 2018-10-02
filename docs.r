
C4.5 [release 8] rule generator	Tue Oct  2 13:34:21 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 1498's class of '0' is illegal

Read 1498 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 102:
    	tory > 0
	->  class p  [98.5%]

Rule 98:
    	tories > 0
	->  class p  [98.4%]

Rule 33:
    	manifesto > 0
	->  class p  [91.2%]

Rule 30:
    	detention > 0
	->  class p  [89.1%]

Rule 20:
    	goldsmith > 0
	->  class p  [79.4%]

Rule 67:
    	mobiles > 0
	->  class t  [95.5%]

Rule 66:
    	viruses > 0
	->  class t  [94.6%]

Rule 31:
    	graphics > 0
	->  class t  [94.4%]

Rule 65:
    	servers > 0
	->  class t  [94.2%]

Rule 45:
    	hardware > 0
	->  class t  [93.0%]

Rule 88:
    	multimedia > 0
	->  class t  [92.6%]

Rule 11:
    	blog > 0
	->  class t  [89.9%]

Rule 52:
    	bn <= 0
    	growth <= 0
    	economy <= 0
    	sec <= 1
    	takeover <= 0
    	economic <= 0
    	investors <= 0
    	prices <= 0
    	exports <= 0
    	saudi <= 0
    	companies > 0
    	hollywood <= 0
    	songs <= 0
    	tories <= 0
    	ad <= 0
	->  class t  [88.9%]

Rule 48:
    	bn <= 0
    	companies <= 0
    	provider > 0
	->  class t  [84.1%]

Rule 14:
    	spyware > 3
	->  class t  [79.4%]

Rule 97:
    	hd > 1
	->  class t  [79.4%]

Rule 35:
    	championships > 0
	->  class s  [96.6%]

Rule 32:
    	companies <= 0
    	slam > 0
	->  class s  [96.3%]

Rule 34:
    	striker > 0
	->  class s  [96.1%]

Rule 28:
    	companies <= 0
    	athens > 0
	->  class s  [95.2%]

Rule 25:
    	finals > 0
	->  class s  [95.0%]

Rule 26:
    	referee > 0
	->  class s  [95.0%]

Rule 29:
    	scrum > 0
	->  class s  [93.6%]

Rule 24:
    	movie <= 0
    	lions > 0
	->  class s  [92.6%]

Rule 18:
    	roddick > 0
	->  class s  [91.2%]

Rule 21:
    	doping > 0
	->  class s  [90.6%]

Rule 19:
    	companies <= 0
    	chart <= 0
    	hollywood <= 0
    	tory <= 0
    	goldsmith <= 0
    	league > 0
	->  class s  [89.3%]

Rule 15:
    	seed > 0
	->  class s  [89.0%]

Rule 101:
    	actress > 0
	->  class e  [97.3%]

Rule 99:
    	firms <= 0
    	singer > 0
	->  class e  [95.8%]

Rule 2:
    	festival > 0
	->  class e  [95.2%]

Rule 23:
    	movie <= 0
    	drama > 0
    	championships <= 0
    	viruses <= 0
	->  class e  [95.0%]

Rule 17:
    	oscars > 0
	->  class e  [94.2%]

Rule 93:
    	starring > 0
	->  class e  [93.9%]

Rule 71:
    	bn <= 0
    	chart > 0
    	graphics <= 0
	->  class e  [92.5%]

Rule 96:
    	hollywood > 0
    	hd <= 1
	->  class e  [91.9%]

Rule 75:
    	album > 0
	->  class e  [91.6%]

Rule 40:
    	musical > 1
	->  class e  [89.9%]

Rule 50:
    	bn <= 0
    	companies <= 0
    	movie > 0
    	lions <= 0
    	mobiles <= 0
    	servers <= 0
	->  class e  [88.7%]

Rule 7:
    	angels > 0
	->  class e  [75.8%]

Rule 72:
    	investors > 0
    	movie <= 0
    	tory <= 0
	->  class b  [97.8%]

Rule 74:
    	economist > 0
	->  class b  [96.1%]

Rule 62:
    	takeover > 0
    	album <= 0
	->  class b  [95.6%]

Rule 60:
    	exports > 0
    	actress <= 0
    	tory <= 0
	->  class b  [94.3%]

Rule 83:
    	bn > 1
    	airline <= 1
    	movie <= 0
    	hollywood <= 0
    	tory <= 0
    	tories <= 0
    	multimedia <= 0
	->  class b  [93.9%]

Rule 39:
    	bank > 0
    	actress <= 0
    	album <= 0
    	singer <= 0
    	musical <= 1
    	tories <= 0
    	viruses <= 0
    	servers <= 0
	->  class b  [92.7%]

Rule 27:
    	economic > 0
    	hollywood <= 0
    	tory <= 0
    	tories <= 0
    	manifesto <= 0
    	servers <= 0
	->  class b  [87.6%]

Rule 12:
    	airline > 0
    	companies <= 0
	->  class b  [84.3%]

Rule 59:
    	saudi > 0
	->  class b  [84.1%]

Rule 61:
    	sec > 1
	->  class b  [82.0%]

Rule 57:
    	prices > 0
    	hollywood <= 0
    	tory <= 0
	->  class b  [75.0%]

Default class: p


Evaluation on training data (1498 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
 102     1   1.5%    93      0 (0.0%)	     0 (0|0) 	p
  98     1   1.6%    27      0 (0.0%)	     0 (0|0) 	p
  33     1   8.8%    15      1 (6.7%)	     1 (1|0) 	p
  30     1  10.9%    10      0 (0.0%)	     0 (0|0) 	p
  20     1  20.6%     3      0 (0.0%)	     0 (0|0) 	p
  67     1   4.5%    30      0 (0.0%)	    13 (13|0) 	t
  66     1   5.4%    25      0 (0.0%)	    15 (15|0) 	t
  31     1   5.6%    22      0 (0.0%)	    11 (11|0) 	t
  65     1   5.8%    17      0 (0.0%)	    11 (11|0) 	t
  45     1   7.0%     9      0 (0.0%)	     9 (9|0) 	t
  88     1   7.4%     7      0 (0.0%)	     6 (6|0) 	t
  11     1  10.1%    13      0 (0.0%)	    10 (10|0) 	t
  52    15  11.1%    40      3 (7.5%)	    36 (37|1) 	t
  48     3  15.9%     7      0 (0.0%)	     7 (7|0) 	t
  14     1  20.6%     3      0 (0.0%)	     3 (3|0) 	t
  97     1  20.6%     3      0 (0.0%)	     3 (3|0) 	t
  35     1   3.4%    40      0 (0.0%)	    19 (19|0) 	s
  32     2   3.7%    34      0 (0.0%)	    20 (20|0) 	s
  34     1   3.9%    35      0 (0.0%)	    16 (16|0) 	s
  28     2   4.8%    18      0 (0.0%)	    12 (12|0) 	s
  25     1   5.0%    12      0 (0.0%)	     7 (7|0) 	s
  26     1   5.0%    17      0 (0.0%)	    15 (15|0) 	s
  29     1   6.4%    18      0 (0.0%)	    14 (14|0) 	s
  24     2   7.4%    12      0 (0.0%)	    11 (11|0) 	s
  18     1   8.8%     8      0 (0.0%)	     6 (6|0) 	s
  21     1   9.4%     8      0 (0.0%)	     8 (8|0) 	s
  19     6  10.7%    36      3 (8.3%)	    33 (33|0) 	s
  15     1  11.0%     7      0 (0.0%)	     7 (7|0) 	s
 101     1   2.7%    50      0 (0.0%)	     3 (3|0) 	e
  99     2   4.2%    53      1 (1.9%)	    24 (25|1) 	e
   2     1   4.8%    14      0 (0.0%)	     4 (4|0) 	e
  23     4   5.0%    13      0 (0.0%)	     7 (7|0) 	e
  17     1   5.8%     8      0 (0.0%)	     3 (3|0) 	e
  93     1   6.1%    16      1 (6.2%)	     4 (5|1) 	e
  71     3   7.5%    18      1 (5.6%)	     8 (9|1) 	e
  96     2   8.1%    16      1 (6.2%)	     9 (9|0) 	e
  75     1   8.4%    16      1 (6.2%)	    14 (14|0) 	e
  40     1  10.1%     4      0 (0.0%)	     4 (4|0) 	e
  50     6  11.3%    11      3 (27.3%)	     8 (8|0) 	e
   7     1  24.2%     2      0 (0.0%)	     2 (2|0) 	e
  72     3   2.2%    61      0 (0.0%)	    18 (18|0) 	b
  74     1   3.9%    31      0 (0.0%)	     2 (2|0) 	b
  62     2   4.4%    22      0 (0.0%)	     6 (6|0) 	b
  60     3   5.7%    26      1 (3.8%)	     7 (8|1) 	b
  83     7   6.1%    93      5 (5.4%)	    47 (51|4) 	b
  39     8   7.3%    32      5 (15.6%)	     9 (12|3) 	b
  27     6  12.4%    35     10 (28.6%)	    13 (18|5) 	b
  12     2  15.7%    15      1 (6.7%)	    11 (11|0) 	b
  59     1  15.9%     3      0 (0.0%)	     3 (3|0) 	b
  61     1  18.0%     3      0 (0.0%)	     3 (3|0) 	b
  57     3  25.0%    28     10 (35.7%)	    17 (18|1) 	b

Tested 1498, errors 299 (20.0%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  317    1   46    1    2	(a): class b
	    2  213   37    1     	(b): class e
	   16    2  254         1	(c): class p
	             88  242     	(d): class s
	   14    5   82    1  173	(e): class t

