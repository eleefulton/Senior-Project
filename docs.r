
C4.5 [release 8] rule generator	Mon Sep 24 17:49:47 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 17's class of '2' is illegal

Read 17 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 3:
    	package > 0
	->  class b  [50.0%]

Rule 2:
    	package <= 0
    	government > 0
	->  class p  [79.4%]

Rule 1:
    	government <= 0
    	title <= 0
    	range <= 0
	->  class s  [75.8%]

Default class: t


Evaluation on training data (17 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   3     1  50.0%     2      0 (0.0%)	     2 (2|0) 	b
   2     2  20.6%     6      0 (0.0%)	     6 (6|0) 	p
   1     3  24.2%     5      0 (0.0%)	     5 (5|0) 	s

Tested 17, errors 2 (11.8%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	    2                   1	(a): class b
	                        1	(b): class e
	              6          	(c): class p
	                   5     	(d): class s
	                        2	(e): class t

