
C4.5 [release 8] rule generator	Thu Oct  4 13:47:08 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 1498's class of '0' is illegal

Read 1498 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 99:
    	technologies > 0
	->  class t  [97.2%]

Rule 44:
    	portable > 0
	->  class t  [96.3%]

Rule 67:
    	mobiles > 0
	->  class t  [95.9%]

Rule 43:
    	xbox > 0
	->  class t  [94.8%]

Rule 45:
    	nokia > 0
	->  class t  [93.6%]

Rule 66:
    	viruses > 0
	->  class t  [93.6%]

Rule 19:
    	spam > 0
	->  class t  [91.7%]

Rule 94:
    	halo > 0
	->  class t  [89.9%]

Rule 12:
    	spammers > 0
	->  class t  [88.2%]

Rule 54:
    	browser > 0
	->  class t  [87.1%]

Rule 58:
    	bittorrent > 1
	->  class t  [75.8%]

Rule 100:
    	tory > 0
	->  class p  [98.5%]

Rule 96:
    	tories > 0
	->  class p  [98.4%]

Rule 40:
    	manifesto > 0
	->  class p  [91.7%]

Rule 6:
    	nhs > 0
	->  class p  [90.6%]

Rule 8:
    	suspects > 0
    	spam <= 0
	->  class p  [89.1%]

Rule 29:
    	striker > 0
	->  class s  [95.9%]

Rule 30:
    	finals > 0
	->  class s  [95.9%]

Rule 28:
    	championships > 0
	->  class s  [95.6%]

Rule 21:
    	market <= 0
    	seed > 0
	->  class s  [94.8%]

Rule 24:
    	athletics > 0
	->  class s  [94.8%]

Rule 17:
    	flanker > 0
	->  class s  [93.9%]

Rule 22:
    	slam > 0
	->  class s  [93.6%]

Rule 26:
    	movie <= 0
    	lions > 0
	->  class s  [93.3%]

Rule 27:
    	scrum > 0
	->  class s  [93.3%]

Rule 18:
    	keeper > 0
	->  class s  [93.0%]

Rule 15:
    	athens > 0
	->  class s  [90.9%]

Rule 16:
    	uefa > 0
	->  class s  [90.6%]

Rule 25:
    	mourinho > 0
	->  class s  [90.6%]

Rule 4:
    	everton > 0
	->  class s  [89.9%]

Rule 9:
    	gara > 2
	->  class s  [75.8%]

Rule 98:
    	singer > 0
    	technologies <= 0
	->  class e  [96.5%]

Rule 62:
    	festival > 0
	->  class e  [96.0%]

Rule 97:
    	oscar > 0
	->  class e  [95.5%]

Rule 20:
    	market <= 0
    	comedy > 0
    	movie <= 0
	->  class e  [95.3%]

Rule 95:
    	actor > 0
    	tory <= 0
    	technologies <= 0
	->  class e  [94.5%]

Rule 64:
    	bn <= 0
    	band > 0
    	tory <= 0
    	tories <= 0
    	lions <= 1
    	technologies <= 0
	->  class e  [93.3%]

Rule 48:
    	rapper > 0
	->  class e  [93.3%]

Rule 47:
    	nominations > 0
	->  class e  [93.2%]

Rule 57:
    	movie > 1
    	technologies <= 0
    	bittorrent <= 1
	->  class e  [92.2%]

Rule 93:
    	chart > 0
    	halo <= 0
	->  class e  [92.1%]

Rule 3:
    	pop > 1
	->  class e  [86.7%]

Rule 73:
    	economy > 0
    	bn <= 0
    	growth > 0
	->  class b  [97.0%]

Rule 68:
    	investors > 0
    	tory <= 0
	->  class b  [95.3%]

Rule 52:
    	economist > 0
	->  class b  [93.9%]

Rule 53:
    	shareholders > 0
	->  class b  [93.2%]

Rule 63:
    	bank > 0
    	actor <= 0
    	singer <= 0
    	tories <= 0
    	mobiles <= 0
    	viruses <= 0
	->  class b  [89.5%]

Rule 77:
    	bn > 0
    	imf <= 0
    	chart <= 0
    	oscar <= 0
    	singer <= 0
    	band <= 0
    	tory <= 0
    	tories <= 0
    	technologies <= 0
    	portable <= 0
	->  class b  [89.2%]

Rule 50:
    	analyst > 0
    	prices > 2
	->  class b  [84.1%]

Rule 37:
    	bmw > 1
	->  class b  [63.0%]

Default class: p


Evaluation on training data (1498 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  99     1   2.8%    49      0 (0.0%)	    17 (17|0) 	t
  44     1   3.7%    21      0 (0.0%)	    13 (13|0) 	t
  67     1   4.1%    15      0 (0.0%)	    11 (11|0) 	t
  43     1   5.2%    13      0 (0.0%)	     7 (7|0) 	t
  45     1   6.4%     8      0 (0.0%)	     4 (4|0) 	t
  66     1   6.4%    17      0 (0.0%)	     9 (9|0) 	t
  19     1   8.3%    10      0 (0.0%)	     5 (5|0) 	t
  94     1  10.1%     2      0 (0.0%)	     2 (2|0) 	t
  12     1  11.8%     2      0 (0.0%)	     2 (2|0) 	t
  54     1  12.9%     6      0 (0.0%)	     6 (6|0) 	t
  58     1  24.2%     5      0 (0.0%)	     5 (5|0) 	t
 100     1   1.5%    93      0 (0.0%)	     0 (0|0) 	p
  96     1   1.6%    31      0 (0.0%)	     0 (0|0) 	p
  40     1   8.3%    16      1 (6.2%)	     0 (0|0) 	p
   6     1   9.4%     4      0 (0.0%)	     1 (1|0) 	p
   8     2  10.9%     7      0 (0.0%)	     0 (0|0) 	p
  29     1   4.1%    33      0 (0.0%)	    20 (20|0) 	s
  30     1   4.1%    31      0 (0.0%)	     5 (5|0) 	s
  28     1   4.4%    24      0 (0.0%)	     9 (9|0) 	s
  21     2   5.2%    12      0 (0.0%)	    10 (10|0) 	s
  24     1   5.2%    15      0 (0.0%)	     5 (5|0) 	s
  17     1   6.1%    21      0 (0.0%)	    10 (10|0) 	s
  22     1   6.4%    22      1 (4.5%)	    16 (16|0) 	s
  26     2   6.7%    16      0 (0.0%)	    13 (13|0) 	s
  27     1   6.7%    10      0 (0.0%)	    10 (10|0) 	s
  18     1   7.0%    11      0 (0.0%)	    10 (10|0) 	s
  15     1   9.1%    11      1 (9.1%)	    10 (10|0) 	s
  16     1   9.4%    12      0 (0.0%)	    10 (10|0) 	s
  25     1   9.4%    10      0 (0.0%)	     9 (9|0) 	s
   4     1  10.1%     7      0 (0.0%)	     7 (7|0) 	s
   9     1  24.2%     3      0 (0.0%)	     3 (3|0) 	s
  98     2   3.5%    74      1 (1.4%)	    21 (22|1) 	e
  62     1   4.0%    27      0 (0.0%)	     9 (9|0) 	e
  97     1   4.5%    41      1 (2.4%)	    10 (11|1) 	e
  20     3   4.7%    14      0 (0.0%)	     9 (9|0) 	e
  95     3   5.5%    23      1 (4.3%)	    14 (15|1) 	e
  64     6   6.7%    22      1 (4.5%)	     9 (9|0) 	e
  48     1   6.7%    10      0 (0.0%)	     5 (5|0) 	e
  47     1   6.8%     2      0 (0.0%)	     2 (2|0) 	e
  57     3   7.8%     4      0 (0.0%)	     3 (3|0) 	e
  93     2   7.9%    13      2 (15.4%)	     8 (8|0) 	e
   3     1  13.3%     2      0 (0.0%)	     2 (2|0) 	e
  73     3   3.0%    46      0 (0.0%)	    14 (14|0) 	b
  68     2   4.7%    53      1 (1.9%)	     9 (10|1) 	b
  52     1   6.1%    20      1 (5.0%)	     2 (3|1) 	b
  53     1   6.8%    25      1 (4.0%)	     4 (4|0) 	b
  63     6  10.5%    46      7 (15.2%)	    14 (18|4) 	b
  77    10  10.8%    98     13 (13.3%)	    75 (83|8) 	b
  50     2  15.9%     3      0 (0.0%)	     3 (3|0) 	b
  37     1  37.0%     3      0 (0.0%)	     3 (3|0) 	b

Tested 1498, errors 353 (23.6%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  271        72          	(a): class b
	    4  226   43          	(b): class e
	   15    3  264          	(c): class p
	    1       104  236     	(d): class s
	    3    3  103    2  148	(e): class t

