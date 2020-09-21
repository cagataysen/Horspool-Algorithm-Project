# Horspool-Algorithm-Project

In this project constructed a system that fills the blanks in a given statement using the input text.
	
  
 Preferred to use Horspool algorithm in this project. Horspool is an algorithm for finding substrings into strings. This algorithm compares each characters of substring to find a word or the same characters into the string. When characters do not match, the search jumps to the next matching position in the pattern by the value indicated in the Shift Table. 
	
  Shift Table indicates how many jumps should it move from the current position to the next. The first step is calculate the value of each letter of the pattern to create the 
  Shift Table, using this formula:

      Value = (length of pattern – index of each letter in the pattern – 1)


The value of the last letter and other letters that are not in the pattern will be the length of the pattern. 

After calculating the value, Shift Table will look like this,
Letter	A	B	C	D	*
Value	3	2	1	4	4
 
        0  1  2  3 
        A  B  C  D

F(A) = 4 – 0 - 1 = 3
F(B) = 4 – 1 – 1 = 2
F(C) = 4 – 2 – 1 = 1
F(D) = 4


After that, pattern and text can comparable. This algorithm starts from the index of the end letter in the pattern. 

-	If the letter matches, then compare with the preceding letter.

-	If it doesn’t match, check its value in the Shift Table.

-	Then, skip the number of spaces that the table value indicates.

-	Repeat this steps until all the letters match. 



	
