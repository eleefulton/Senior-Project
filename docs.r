
C4.5 [release 8] rule generator	Thu Oct 11 00:08:00 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 997's class of '0' is illegal

Read 997 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 43:
    	los > 0
    	more <= 4
	->  class e  [83.8%]

Rule 57:
    	bank <= 0
    	oil <= 0
    	operations <= 0
    	inflation <= 0
    	policies > 0
	->  class p  [90.2%]

Rule 47:
    	bank <= 0
    	oil <= 0
    	taxes > 0
    	generation <= 0
	->  class p  [83.8%]

Rule 23:
    	bank <= 0
    	correspondent > 0
    	more <= 2
	->  class p  [82.0%]

Rule 8:
    	shareholder > 0
	->  class b  [91.7%]

Rule 15:
    	trillion > 0
    	industry <= 0
	->  class b  [89.1%]

Rule 52:
    	oil <= 0
    	investments > 0
	->  class b  [89.1%]

Rule 54:
    	shareholders > 0
	->  class b  [87.9%]

Rule 60:
    	operations > 0
	->  class b  [86.6%]

Rule 61:
    	oil > 0
	->  class b  [86.4%]

Rule 59:
    	bank > 0
    	mobiles <= 0
	->  class b  [85.1%]

Rule 17:
    	airbus > 0
	->  class b  [75.8%]

Rule 6:
    	plant > 0
	->  class b  [73.1%]

Rule 42:
    	trading > 0
    	los <= 0
	->  class b  [70.6%]

Rule 45:
    	consumer > 0
    	more <= 0
	->  class b  [70.0%]

Rule 58:
    	inflation > 0
	->  class b  [58.6%]

Rule 62:
    	mobiles > 0
	->  class t  [94.2%]

Rule 7:
    	umd > 0
	->  class t  [70.7%]

Rule 9:
    	airbus <= 0
    	bank <= 0
    	oil <= 0
    	assets <= 0
    	trillion <= 0
    	taxes <= 0
    	trading <= 0
    	debt <= 0
    	deter <= 0
    	policies <= 0
    	dream <= 0
    	more > 1
    	washington <= 0
	->  class t  [52.5%]

Rule 1:
    	bank <= 0
    	analyst <= 0
    	oil <= 0
    	operations <= 0
    	taxes <= 0
    	trading <= 0
    	industry <= 0
    	consumer <= 0
    	los <= 0
    	policies <= 0
    	established <= 0
    	mobiles <= 0
    	more <= 0
	->  class s  [42.1%]

Default class: s


Evaluation on training data (997 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  43     2  16.2%    23      2 (8.7%)	    20 (21|1) 	e
  57     5   9.8%    26      1 (3.8%)	    21 (21|0) 	p
  47     4  16.2%    19      2 (10.5%)	    14 (16|2) 	p
  23     3  18.0%     6      0 (0.0%)	     6 (6|0) 	p
   8     1   8.3%    16      0 (0.0%)	     7 (7|0) 	b
  15     2  10.9%    12      0 (0.0%)	     4 (4|0) 	b
  52     2  10.9%    10      0 (0.0%)	     5 (5|0) 	b
  54     1  12.1%    17      1 (5.9%)	     5 (6|1) 	b
  60     1  13.4%    21      2 (9.5%)	    11 (11|0) 	b
  61     1  13.6%    40      5 (12.5%)	    18 (19|1) 	b
  59     2  14.9%    31      6 (19.4%)	    20 (20|0) 	b
  17     1  24.2%     4      0 (0.0%)	     4 (4|0) 	b
   6     1  26.9%     7      1 (14.3%)	     6 (6|0) 	b
  42     2  29.4%    20      8 (40.0%)	    11 (11|0) 	b
  45     2  30.0%     5      1 (20.0%)	     4 (4|0) 	b
  58     1  41.4%     4      0 (0.0%)	     4 (4|0) 	b
  62     1   5.8%    23      0 (0.0%)	     4 (4|0) 	t
   7     1  29.3%     4      0 (0.0%)	     3 (3|0) 	t
   9    13  47.5%   137     67 (48.9%)	    54 (70|16) 	t
   1    13  57.9%   362    198 (54.7%)	     0 (0|0) 	s

Tested 997, errors 454 (45.5%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	  163         3   54   10	(a): class b
	    5   21       124   15	(b): class e
	   10        48  115   26	(c): class p
	    2    1       214   16	(d): class s
	    7    1        65   97	(e): class t

