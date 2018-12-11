
C4.5 [release 8] rule generator	Tue Dec 11 12:47:00 2018
-------------------------------

    Options:
	File stem <./output/docs>

ERROR:  case 338's class of '0' is illegal

Read 338 cases (250 attributes) from ./output/docs

------------------
Processing tree 0

Final rules from tree 0:

Rule 31:
    	tory > 0
	->  class p  [94.6%]

Rule 29:
    	commons > 0
	->  class p  [91.2%]

Rule 17:
    	conservative > 0
	->  class p  [89.1%]

Rule 22:
    	mps > 1
	->  class p  [89.1%]

Rule 23:
    	democrats > 0
	->  class p  [89.1%]

Rule 6:
    	democracy > 1
	->  class p  [63.0%]

Rule 33:
    	users > 0
	->  class t  [94.6%]

Rule 30:
    	websites > 0
	->  class t  [92.2%]

Rule 32:
    	gaming > 0
	->  class t  [89.9%]

Rule 27:
    	mobiles > 0
	->  class t  [82.0%]

Rule 26:
    	audio > 0
	->  class t  [79.4%]

Rule 25:
    	music > 0
    	users <= 0
    	gaming <= 0
    	mobiles <= 0
    	audio <= 0
	->  class e  [93.3%]

Rule 21:
    	comedy > 0
    	users <= 0
	->  class e  [90.6%]

Rule 24:
    	actor > 0
	->  class e  [90.6%]

Rule 28:
    	films > 0
    	users <= 0
    	gaming <= 0
	->  class e  [87.9%]

Rule 18:
    	charts > 0
	->  class e  [82.0%]

Rule 16:
    	growth > 0
    	tory <= 0
    	mps <= 1
    	users <= 0
    	gaming <= 0
    	mobiles <= 0
	->  class b  [91.5%]

Rule 19:
    	bn > 0
    	films <= 0
    	tory <= 0
    	human <= 0
    	users <= 0
    	websites <= 0
	->  class b  [90.3%]

Rule 9:
    	companies > 0
    	do <= 0
    	users <= 0
    	gaming <= 0
    	websites <= 0
    	mobiles <= 0
	->  class b  [89.8%]

Rule 13:
    	shares > 1
	->  class b  [89.1%]

Rule 4:
    	growth <= 0
    	shares <= 1
    	sales <= 1
    	bn <= 0
    	companies <= 0
    	analysts <= 0
    	prices <= 0
    	actor <= 0
    	music <= 0
    	films <= 0
    	comedy <= 0
    	rock <= 0
    	charts <= 0
    	movie <= 0
    	tory <= 0
    	mps <= 1
    	commons <= 0
    	conservative <= 0
    	democrats <= 0
    	democracy <= 1
    	human <= 0
    	users <= 0
    	gaming <= 0
    	websites <= 0
    	mobiles <= 0
    	personal <= 1
	->  class s  [76.3%]

Default class: p


Evaluation on training data (338 items):

Rule  Size  Error  Used  Wrong	          Advantage
----  ----  -----  ----  -----	          ---------
  31     1   5.4%    25      0 (0.0%)	     0 (0|0) 	p
  29     1   8.8%     9      0 (0.0%)	     0 (0|0) 	p
  17     1  10.9%     4      0 (0.0%)	     0 (0|0) 	p
  22     1  10.9%     4      0 (0.0%)	     0 (0|0) 	p
  23     1  10.9%     6      0 (0.0%)	     0 (0|0) 	p
   6     1  37.0%     3      0 (0.0%)	     0 (0|0) 	p
  33     1   5.4%    25      0 (0.0%)	    12 (12|0) 	t
  30     1   7.8%     7      0 (0.0%)	     6 (6|0) 	t
  32     1  10.1%    10      0 (0.0%)	     5 (5|0) 	t
  27     1  18.0%     5      0 (0.0%)	     5 (5|0) 	t
  26     1  20.6%     2      0 (0.0%)	     2 (2|0) 	t
  25     5   6.7%    20      0 (0.0%)	    15 (15|0) 	e
  21     2   9.4%    13      0 (0.0%)	     4 (4|0) 	e
  24     1   9.4%     9      0 (0.0%)	     3 (3|0) 	e
  28     3  12.1%     8      1 (12.5%)	     7 (7|0) 	e
  18     1  18.0%     3      0 (0.0%)	     3 (3|0) 	e
  16     6   8.5%    30      1 (3.3%)	    16 (16|0) 	b
  19     6   9.7%    31      2 (6.5%)	    14 (15|1) 	b
   9     6  10.2%     9      1 (11.1%)	     8 (8|0) 	b
  13     1  10.9%     4      0 (0.0%)	     4 (4|0) 	b
   4    26  23.7%    90     18 (20.0%)	    66 (72|6) 	s

Tested 338, errors 37 (10.9%)   <<


	  (a)  (b)  (c)  (d)  (e)	<-classified as
	 ---- ---- ---- ---- ----
	   70         6    4     	(a): class b
	    1   52    3    4     	(b): class e
	    1        58    6     	(c): class p
	              2   72     	(d): class s
	    2    1    3    4   49	(e): class t

