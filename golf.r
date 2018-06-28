
C4.5 [release 8] rule generator	Thu Jun 28 11:07:51 2018
-------------------------------

    Options:
	File stem <golf>

Read 14 cases (4 attributes) from golf

------------------
Processing tree 0

Final rules from tree 0:

Rule 2:
    	outlook = overcast
	->  class Play  [70.7%]

Rule 4:
    	outlook = rain
    	windy = false
	->  class Play  [63.0%]

Rule 1:
    	outlook = sunny
    	humidity > 75
	->  class Don't Play  [63.0%]

Rule 3:
    	outlook = rain
    	windy = true
	->  class Don't Play  [50.0%]

Default class: Play


Evaluation on training data (14 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
   2     1  29.3%     4      0 (0.0%)	     0 (0|0) 	Play
   4     2  37.0%     3      0 (0.0%)	     0 (0|0) 	Play
   1     2  37.0%     3      0 (0.0%)	     3 (3|0) 	Don't Play
   3     2  50.0%     2      0 (0.0%)	     2 (2|0) 	Don't Play

Tested 14, errors 0 (0.0%)   <<


	  (a)  (b)	<-classified as
	 ---- ----
	    9     	(a): class Play
	         5	(b): class Don't Play

