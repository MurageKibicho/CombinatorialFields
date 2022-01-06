# Combinatorial Finite Field Cryptography
## Project Summary
We propose a method for constructing finite fields whose order is a combination, ***n choose k***. 
We call these ***combinatorial finite fields***. 
Combinatorial finite fields allow for the construction of ***combinatorial groups***. 
These are commutative mathematical groups with well defined 
group operations, just like elliptic curves.
These combinatorial groups
are important because they provide extremely fast and extremely secure hash constructions.
We aim to provide a faster alternative to elliptic curve cryptography in the [Pedersen Hash](https://iden3-docs.readthedocs.io/en/latest/iden3_repos/research/publications/zkproof-standards-workshop-2/pedersen-hash/pedersen.html)
and faster constructions of [zero knowledge proofs](https://en.wikipedia.org/wiki/Zero-knowledge_proof#Practical_examples).

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

### Summary
- We introduce a numeral system based on binomial coefficients.
- We define fast group operations within the number system based on binomial coefficients.
- We present an analog to the discrete logarithm problem using binomial coefficents.

