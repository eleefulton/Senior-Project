
C4.5 [release 8] rule generator	Fri Sep 21 17:38:34 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 50's class of '0' is illegal

Read 50 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 3:
    	got > 0
	->  class e  [75.8%]

Rule 2:
    	show > 0
	->  class e  [70.7%]

Rule 6:
    	promised > 0
	->  class p  [70.7%]

Rule 5:
    	parties > 0
	->  class p  [63.0%]

Rule 8:
    	game > 0
    	allows <= 0
	->  class s  [75.8%]

Rule 7:
    	doping > 0
	->  class s  [50.0%]

Rule 9:
    	allows > 0
	->  class t  [63.0%]

Rule 10:
    	via > 0
	->  class t  [63.0%]

Rule 1:
    	show <= 0
    	got <= 0
    	charles <= 0
    	parties <= 0
    	promised <= 0
    	doping <= 0
    	game <= 0
    	via <= 0
    	allows <= 0
	->  class b  [78.0%]

Default class: e


Evaluation on training data (50 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   3     1  24.2%     5      0 (0.0%)	     0 (0|0) 	e
   2     1  29.3%     2      0 (0.0%)	     0 (0|0) 	e
   6     1  29.3%     4      0 (0.0%)	     4 (4|0) 	p
   5     1  37.0%     3      0 (0.0%)	     3 (3|0) 	p
   8     2  24.2%     5      0 (0.0%)	     5 (5|0) 	s
   7     1  50.0%     2      0 (0.0%)	     2 (2|0) 	s
   9     1  37.0%     3      0 (0.0%)	     2 (2|0) 	t
  10     1  37.0%     2      0 (0.0%)	     2 (2|0) 	t
   1     9  22.0%    22      3 (13.6%)	    17 (19|2) 	b

Tested 50, errors 4 (8.0%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   19                    	(a): class b
	    2    8               	(b): class e
	         1    7          	(c): class p
	    1              7     	(d): class s
	                        5	(e): class t

