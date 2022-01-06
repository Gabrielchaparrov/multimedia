
# Hash Tables

Implementation of a program that allows you to determine whether a string of characters can be a secure password or not. A password is valid (secure) if:

- **1.** Contains at least 8 alphanumeric characters (English alphabet: no accents, no ñ, etc),
- **2.** Once the numeric characters have been eliminated, the resulting string is not part of the dictionary of the Spanish language,
- **3.** And contains one (and only one) digit.

To validate criterion **2.** of this problem, it is necessary to store all the words in the Spanish dictionary in a data structure that allows searching in an acceptable time and efficiently managing memory. 

One possibility is to consider a scatter table.

The file **spanish_lex.lex** contains 91656 words. Words (one per line) begin with the * character and end with #. Accents are represented by the vowel followed by the character \, the letter ñ as the character n followed by ~, and the letter ü as the character u followed by $. This file is distributed by the University of Michigan and, for this practice it has been preprocessed to eliminate the set phrases (they contain blank spaces), as we will not consider them in this problem.

This project manages scatter tables. In order to analyze how the choice of the transformation that distributes the keys in the vector influences the number of collisions and the load factor, two dispersion functions are considered: 
- **1.** The Hash1 function, that only takes into account the characters that make up the word
<img src="https://render.githubusercontent.com/render/math?math=Hash1(c) = %5Cdisplaystyle%5Csum_%7Bi%3D1%7D%5E%5Clongitud%20remainder(c_i/m)"><br>

- **2.** The Hash2 function, which also considers the positions they occupy.
<img src="https://render.githubusercontent.com/render/math?math=Hash2(c) = %5Cdisplaystyle%5Csum_%7Bi%3D1%7D%5E%5Clongitud%20remainder(c_i*2^i/m)"><br>


## Task 2: Test the passwords

Test of the program with the strings: "locomotora1", "agu25a", "ordenador2", "sssssss22ss", "4rarbrcrd", "sal9ypimienta" and "programmer2". For each of them, the program indicates if it is a valid password. In the case of a non-secure password, the program must indicate the reason.

### Result:


## Task 3: Compare the hash functions
Extends the definition of the Table class to keep a counter for the number of collisions and to determine the load factor.

### Result:

