
C4.5 [release 8] rule generator	Fri Sep 21 17:51:52 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 49's class of '0' is illegal

Read 49 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 8:
    	chart > 0
	->  class e  [75.8%]

Rule 6:
    	election > 0
	->  class p  [70.7%]

Rule 7:
    	concern > 0
	->  class p  [63.0%]

Rule 4:
    	criminally > 0
	->  class p  [50.0%]

Rule 3:
    	company > 0
    	people <= 0
	->  class b  [70.0%]

Rule 2:
    	prices > 1
	->  class b  [50.0%]

Rule 1:
    	company <= 0
    	prices <= 1
    	chart <= 0
    	people <= 0
    	criminally <= 0
	->  class s  [82.2%]

Rule 5:
    	chart <= 0
    	people > 0
    	election <= 0
    	concern <= 0
	->  class t  [80.9%]

Default class: t


Evaluation on training data (49 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   8     1  24.2%     5      0 (0.0%)	     5 (5|0) 	e
   6     1  29.3%     4      0 (0.0%)	     2 (2|0) 	p
   7     1  37.0%     2      0 (0.0%)	     2 (2|0) 	p
   4     1  50.0%     1      0 (0.0%)	     1 (1|0) 	p
   3     2  30.0%     8      1 (12.5%)	     6 (7|1) 	b
   2     1  50.0%     2      0 (0.0%)	     2 (2|0) 	b
   1     5  17.8%    14      1 (7.1%)	    12 (13|1) 	s
   5     4  19.1%    13      1 (7.7%)	     0 (0|0) 	t

Tested 49, errors 3 (6.1%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	    9                    	(a): class b
	         5              1	(b): class e
	              7          	(c): class p
	                  13     	(d): class s
	    1              1   12	(e): class t

