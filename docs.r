
C4.5 [release 8] rule generator	Mon Sep 24 14:46:27 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 6's class of '3' is illegal

Read 6 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 1:
    	mr <= 0
	->  class s  [70.7%]

Default class: b


Evaluation on training data (6 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   1     1  29.3%     4      0 (0.0%)	     4 (4|0) 	s

Tested 6, errors 1 (16.7%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	    1                    	(a): class b
	                         	(b): class e
	                         	(c): class p
	                   4     	(d): class s
	    1                    	(e): class t

