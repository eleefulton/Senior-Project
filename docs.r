
C4.5 [release 8] rule generator	Fri Oct 19 12:57:55 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 1346's class of '0' is illegal

Read 1346 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 93:
    	apple > 0
	->  class t  [96.0%]

Rule 19:
    	mobiles > 0
	->  class t  [94.8%]

Rule 54:
    	windows > 0
	->  class t  [94.6%]

Rule 37:
    	economy <= 0
    	bn <= 0
    	shares <= 0
    	firms > 1
    	prices <= 0
	->  class t  [94.2%]

Rule 48:
    	developers > 0
	->  class t  [94.2%]

Rule 82:
    	gadget > 0
	->  class t  [93.3%]

Rule 5:
    	xbox > 0
	->  class t  [93.0%]

Rule 39:
    	spam > 0
	->  class t  [91.7%]

Rule 88:
    	multimedia > 0
	->  class t  [91.7%]

Rule 45:
    	handset > 1
	->  class t  [88.2%]

Rule 7:
    	handheld > 1
	->  class t  [85.7%]

Rule 11:
    	blog > 0
	->  class t  [84.1%]

Rule 36:
    	wi > 4
	->  class t  [63.0%]

Rule 47:
    	los > 2
	->  class t  [50.0%]

Rule 96:
    	tory > 0
	->  class p  [98.2%]

Rule 70:
    	tories > 0
	->  class p  [97.9%]

Rule 17:
    	manifesto > 0
	->  class p  [94.2%]

Rule 18:
    	blunkett > 0
	->  class p  [92.6%]

Rule 13:
    	falconer > 0
	->  class p  [85.7%]

Rule 68:
    	economy > 0
    	him > 0
	->  class p  [79.4%]

Rule 24:
    	championships <= 0
    	hunting > 0
	->  class p  [70.0%]

Rule 9:
    	guantanamo > 3
	->  class p  [63.0%]

Rule 81:
    	rebate > 2
	->  class p  [50.0%]

Rule 95:
    	actress > 0
	->  class e  [97.0%]

Rule 43:
    	festival > 0
	->  class e  [95.6%]

Rule 55:
    	prices <= 0
    	chart > 0
    	los <= 0
	->  class e  [95.3%]

Rule 69:
    	oscar > 0
	->  class e  [94.7%]

Rule 94:
    	singer > 0
	->  class e  [93.8%]

Rule 52:
    	musical > 1
	->  class e  [92.2%]

Rule 53:
    	drama > 0
	->  class e  [90.3%]

Rule 44:
    	movie > 0
    	him > 0
	->  class e  [89.9%]

Rule 46:
    	artist > 0
    	los <= 2
    	developers <= 0
	->  class e  [87.5%]

Rule 42:
    	novel > 0
    	apple <= 0
    	handset <= 1
	->  class e  [86.0%]

Rule 26:
    	squad > 0
    	developers <= 0
	->  class s  [97.3%]

Rule 23:
    	slam > 0
    	windows <= 0
	->  class s  [96.4%]

Rule 25:
    	championships > 0
	->  class s  [96.1%]

Rule 16:
    	flanker > 0
	->  class s  [94.6%]

Rule 15:
    	athens > 0
	->  class s  [94.4%]

Rule 20:
    	referee > 0
	->  class s  [94.2%]

Rule 4:
    	finals > 0
	->  class s  [93.9%]

Rule 22:
    	midfielder > 0
	->  class s  [93.0%]

Rule 12:
    	keeper > 0
	->  class s  [92.2%]

Rule 21:
    	doping > 0
	->  class s  [91.7%]

Rule 8:
    	economy <= 0
    	bn <= 0
    	bank <= 0
    	economic <= 0
    	prices <= 0
    	actress <= 0
    	oscar <= 0
    	chart <= 0
    	movie <= 0
    	singer <= 0
    	awards <= 0
    	artist <= 0
    	him > 0
    	tory <= 0
    	tories <= 0
    	blunkett <= 0
    	school <= 0
    	manifesto <= 0
    	guantanamo <= 3
    	falconer <= 0
    	apple <= 0
    	spam <= 0
    	blog <= 0
    	hunting <= 0
	->  class s  [83.6%]

Rule 65:
    	oil > 0
    	him <= 0
    	tory <= 0
	->  class b  [97.8%]

Rule 72:
    	economist > 0
	->  class b  [96.2%]

Rule 74:
    	bn > 0
    	earnings > 0
    	tory <= 0
	->  class b  [93.6%]

Rule 77:
    	bn > 0
    	firms > 0
    	gadget <= 0
	->  class b  [93.6%]

Rule 14:
    	bank > 0
    	prices <= 0
    	actress <= 0
    	musical <= 0
    	singer <= 0
    	artist <= 0
    	tories <= 0
    	spam <= 0
    	windows <= 0
	->  class b  [93.2%]

Rule 71:
    	shares > 0
	->  class b  [92.8%]

Rule 87:
    	bn > 1
    	housing <= 0
    	movie <= 0
    	tory <= 0
    	multimedia <= 0
	->  class b  [91.4%]

Rule 91:
    	housing > 0
    	tories <= 0
	->  class b  [88.5%]

Rule 60:
    	bank > 0
    	prices > 0
	->  class b  [87.9%]

Rule 58:
    	firms > 0
    	prices > 0
	->  class b  [85.2%]

Rule 29:
    	economic > 0
    	mortgage <= 0
    	oscar <= 0
    	tory <= 0
    	tories <= 0
	->  class b  [83.1%]

Default class: t


Evaluation on training data (1346 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  93     1   4.0%    34      0 (0.0%)	     0 (0|0) 	t
  19     1   5.2%    18      0 (0.0%)	     3 (3|0) 	t
  54     1   5.4%    19      0 (0.0%)	     0 (0|0) 	t
  37     5   5.8%    15      0 (0.0%)	     0 (0|0) 	t
  48     1   5.8%    14      0 (0.0%)	     0 (0|0) 	t
  82     1   6.7%     6      0 (0.0%)	     0 (0|0) 	t
   5     1   7.0%     8      0 (0.0%)	     1 (1|0) 	t
  39     1   8.3%    13      0 (0.0%)	     1 (1|0) 	t
  88     1   8.3%     3      0 (0.0%)	     0 (0|0) 	t
  45     1  11.8%     1      0 (0.0%)	     0 (0|0) 	t
   7     1  14.3%     4      0 (0.0%)	     0 (0|0) 	t
  11     1  15.9%     7      0 (0.0%)	     1 (1|0) 	t
  36     1  37.0%     3      0 (0.0%)	     0 (0|0) 	t
  47     1  50.0%     2      0 (0.0%)	     0 (0|0) 	t
  96     1   1.8%    77      0 (0.0%)	    27 (27|0) 	p
  70     1   2.1%    24      0 (0.0%)	    19 (19|0) 	p
  17     1   5.8%    11      0 (0.0%)	    11 (11|0) 	p
  18     1   7.4%     8      0 (0.0%)	     8 (8|0) 	p
  13     1  14.3%     8      0 (0.0%)	     7 (7|0) 	p
  68     2  20.6%     5      1 (20.0%)	     3 (4|1) 	p
  24     2  30.0%    10      2 (20.0%)	     6 (8|2) 	p
   9     1  37.0%     3      0 (0.0%)	     3 (3|0) 	p
  81     1  50.0%     2      0 (0.0%)	     2 (2|0) 	p
  95     1   3.0%    45      0 (0.0%)	     8 (8|0) 	e
  43     1   4.4%    24      0 (0.0%)	    10 (10|0) 	e
  55     3   4.7%    26      0 (0.0%)	    15 (15|0) 	e
  69     1   5.3%    21      1 (4.8%)	     8 (8|0) 	e
  94     1   6.2%    39      1 (2.6%)	    28 (28|0) 	e
  52     1   7.8%     7      0 (0.0%)	     6 (6|0) 	e
  53     1   9.7%    13      1 (7.7%)	    11 (12|1) 	e
  44     2  10.1%     5      0 (0.0%)	     5 (5|0) 	e
  46     3  12.5%    13      1 (7.7%)	    11 (12|1) 	e
  42     3  14.0%     7      0 (0.0%)	     7 (7|0) 	e
  26     2   2.7%    51      0 (0.0%)	    12 (12|0) 	s
  23     2   3.6%    27      0 (0.0%)	     7 (7|0) 	s
  25     1   3.9%    28      0 (0.0%)	    12 (12|0) 	s
  16     1   5.4%    11      0 (0.0%)	     7 (7|0) 	s
  15     1   5.6%    18      0 (0.0%)	     7 (7|0) 	s
  20     1   5.8%    16      0 (0.0%)	    10 (10|0) 	s
   4     1   6.1%     7      0 (0.0%)	     5 (5|0) 	s
  22     1   7.0%    16      0 (0.0%)	     7 (7|0) 	s
  12     1   7.8%     8      0 (0.0%)	     5 (5|0) 	s
  21     1   8.3%     7      0 (0.0%)	     7 (7|0) 	s
   8    24  16.4%    60     17 (28.3%)	    40 (43|3) 	s
  65     3   2.2%    62      0 (0.0%)	     9 (9|0) 	b
  72     1   3.8%    26      0 (0.0%)	     3 (3|0) 	b
  74     3   6.4%    21      0 (0.0%)	     3 (3|0) 	b
  77     3   6.4%    26      1 (3.8%)	     5 (5|0) 	b
  14     9   6.8%    39      2 (5.1%)	    11 (11|0) 	b
  71     1   7.2%    33      1 (3.0%)	    21 (21|0) 	b
  87     5   8.6%    42      5 (11.9%)	    28 (30|2) 	b
  91     2  11.5%     8      1 (12.5%)	     3 (3|0) 	b
  60     2  12.1%     6      0 (0.0%)	     3 (3|0) 	b
  58     2  14.8%     5      1 (20.0%)	     3 (4|1) 	b
  29     5  16.9%    24     10 (41.7%)	    10 (14|4) 	b

Tested 1346, errors 277 (20.6%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  271         1        38	(a): class b
	    1  196         2   42	(b): class e
	   13    2  145   12   76	(c): class p
	                 232   76	(d): class s
	    7    2    2    3  225	(e): class t

