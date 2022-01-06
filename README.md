# Combinatorial Finite Field Cryptography
## Project Summary
We propose a method for constructing finite fields whose order is a combination, ***n choose k***. 
We call these ***combinatorial finite fields***. 
Combinatorial finite fields allow for the construction of ***combinatorial groups***. 
These are commutative mathematical structures with well defined 
group operations, just like elliptic curves.
These combinatorial groups
are important because they provide extremely fast and extremely secure hash constructions.
We aim to provide a fast alternative to elliptic curve cryptography in the [Pedersen Hash](https://iden3-docs.readthedocs.io/en/latest/iden3_repos/research/publications/zkproof-standards-workshop-2/pedersen-hash/pedersen.html)
and fast constructions of [zero knowledge proofs](https://en.wikipedia.org/wiki/Zero-knowledge_proof#Practical_examples).
\
This proposal seeks to fund research on the properties of combinatorial finite fields.

### A Friendly Introduction to Finite Fields
Finite fields are beautiful mathematical structures used in cryptography, data transmission, computer circuit design and even the clock in your home.
Finite fields are beautiful because they have lots of structure. This means that really simple operations like multiplication and addition
are well defined in finite fields. Finite fields get their structure because we always know the value of infinity. If, for instance, we set the value of infinity to 12, the we can make a clock. We can count *0,1,2,3,4,5,6,7,8,9,10,11* and when we get to 12, we start again. Literally, and [mathematically](https://math.stackexchange.com/questions/2186685/every-finite-field-is-perfect), every finite field is perfect! 
\
Finite fields are useful in cryptography when we set the value of infinity to a large prime number.

### A Friendly Introduction to Combinatorics
A combination *n choose k* is the number of ways you can choose k elements from a total of n elements. For example, if you have 5 poker cards and you only need to choose 3, there are *5 choose 3* ways to pick the cards you want. N choose k 

## A Technical Introduction to Combinatorial Finite Fields
### Definitions
- ***N*** - the set of natural numbers.
- [***Binomial coefficient***](https://en.wikipedia.org/wiki/Binomial_coefficient) - integer result of calculating ***n choose k***.
- [***Bitmap***](https://en.wikipedia.org/wiki/Bit_array) - a compact data structure for storing bits.
- [***Combinatorial number system***](https://en.wikipedia.org/wiki/Combinatorial_number_system) - a mixed-radix numeral system for representing 
integers as a sum of binomial coefficients. 
- ***Combinatorial finite field*** - a finite field whose order is a binomial coefficient.

### Technical Summary
- We introduce a numeral system based on binomial coefficients.
- We introduce bitmaps and show their relationship to integer sequences.
- We show how to construct a combinatorial finite field.
- We present our research goals.


### Introduction to the combinatorial number system
Any natural number ***N*** can be uniquely written a sum of binomial coefficients. This is called the combinatorial representation of an integer
and this numeral system is called the combinatorial number system.
This combinatorial number system provides a bijection between the natural numbers and integer sequences.
This means that we can create lexicographic orderings of integer sequences. This branch of mathematics is called [enumerative combinatorics](https://en.wikipedia.org/wiki/Enumerative_combinatorics).
The combinatorial number system is important because it allows us to represent integer sequences [strictly increasing](https://en.wikipedia.org/wiki/Monotonic_function) as natural numbers. 
\
[This](http://math0.wvstateu.edu/~baker/cs405/code/Combinadics.html) greedy algorithm is used to find the combinatorial representation of an integer.

1. Find the largest binomial coefficient such that ![akChoosek](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/akChooseKleqN.png)
2. Subtract to find the residue ![NminusAkChoosek](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/NMinusBinomial.png)
3. Find the largest binomial coefficient such that ![Repeat](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/repeat.png)

#### **Example:** Find the combinatorial representation of ![n63K4](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/n63K4.png)
![Convert to Binomial](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/conversionToBinomials.png)
\
To **reverse** the process, sum your list of binomial coefficients
\
![Sum](https://raw.githubusercontent.com/PostingsCompress/PostingsWebsite/main/sum130.png)

### Introduction to Bitmaps
Bitmaps are data structures used in search engines for extremely fast indexing. The data structure offers extremely fast 
operations becasue a bitmap is an array of bits. 
\
For example, (0,1,0,1) is a bitmap
with 4 elements. Assuming the leftmost bit is at index 0, then this bitmap has true boolean values at index 1 and index 3.
\
Bitmaps are used in search engines because they provide a convenient representation of integer sequences. 
To convert an integer sequence into a bitmap,
- Create an empty bit array whose length is equal to 1+ the value of the largest integer in the sequence.
- Set true the element of the bit array corresponding to each integer in the sequence.

### **Example:** Find the bitmap representation of the sequence 2,4,6,7
- Create an array of length 8, : {0,0,0,0,0,0,0}
- Set index 7 to true: {0,0,0,0,0,0,0,1}
- Set index 6 to true: {0,0,0,0,0,0,1,1}
- Set index 4 to true: {0,0,0,0,1,0,1,1}
- Set index 2 to true: {0,0,1,0,1,0,1,1}
Therefore ***2,4,6,7*** is equivalent to the bitmap ***{0,0,1,0,1,0,1,1}***

### Constructing Combinatorial Finite Fields
A combinatorial finite field is a finite field whose order is a binomial coefficient. The simplest construction is enumerating the set of integers from
*0* to *n choose k*. This is insignificant on its own.

As mentioned before, the combinatorial number system offers a bijection between the natural numbers and integer sequences. Also, as shown in the 
previous section, bitmaps offer a bitwise representation of integer sequences. Therefore, we can construct combinatorial fields as ordered sets of bitmaps.

#### Algorithm
For every integer less than *n choose k*:
- Find the combinatorial representation of the integer.
- Convert the combinatorial representation into an bitmap.


### **Example:** Construct the Combinatorial field of order (5 choose 3)
  - 0: 11100
  - 1: 11010
  - 2: 10110
  - 3: 01110
  - 4: 11001
  - 5: 10101
  - 6: 01101
  - 7: 10011
  - 8: 01011
  - 9: 00111
#### Interesting properties of combinatorial finite fields
- They are symmetric along the middle element of the field.ie (In the example, element 0 is a reflection of element 9)
- They form a boolean algebra. This is necessary for the construction of ***combinatorial groups*** because [every boolean algebra is a group](http://www.markability.net/group.htm#:~:text=of%20a%20finite%20Boolean%20Algebra,of%20associativity%2C%20identity%20and%20invertibility.&text=(iv)%20that%20the%20inverse%20of%20any%20given%20element%20is%20unique.)
 
 ### Research Goals
 Our goal is to develop the mathematics needed to work with combinatorial finite fields. Specifically, we need to figure out if it is possible to construct
 groups whose order is a prime number. We also aim to define a combinatorial analog to the discrete logarithm problem. This is necessary for cryptographic applications.
 \
 Ultimately, we want to find out if we can make secure cryptographic hashes that can be verified extremely fast.

