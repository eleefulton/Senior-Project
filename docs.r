
C4.5 [release 8] rule generator	Mon Sep 24 17:32:42 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 17's class of '0' is illegal

Read 17 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 5:
    	film > 0
	->  class e  [50.0%]

Rule 4:
    	minister > 0
	->  class p  [63.0%]

Rule 3:
    	film <= 0
    	his > 0
	->  class s  [63.0%]

Default class: b


Evaluation on training data (17 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   5     1  50.0%     2      0 (0.0%)	     2 (2|0) 	e
   4     1  37.0%     3      0 (0.0%)	     3 (3|0) 	p
   3     2  37.0%     3      0 (0.0%)	     3 (3|0) 	s

Tested 17, errors 3 (17.6%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	    6                    	(a): class b
	         2               	(b): class e
	              3          	(c): class p
	                   3     	(d): class s
	    3                    	(e): class t

