# Combinatorial Finite Field Cryptography
## Project Summary
We propose a method for constructing finite fields whose order is a combination, ***n choose k***. 
We call these ***combinatorial finite field*s**. 
A combinatorial finite fields allow for extremely fast and extremely secure hash constructions.
We aim to provide a faster alternative to elliptic curve cryptography in the [Pedersen Hash](https://iden3-docs.readthedocs.io/en/latest/iden3_repos/research/publications/zkproof-standards-workshop-2/pedersen-hash/pedersen.html)
and faster constructions of [zero knowledge proofs](https://en.wikipedia.org/wiki/Zero-knowledge_proof#Practical_examples).

### A Friendly Introduction to Finite Fields
Finite fields are beautiful mathematical structures used in cryptography, data transmission, computer circuit design and even the clock in your home.
Finite fields are beautiful because they have lots of structure. This means that really simple operations like multiplication and addition
are well defined in finite fields. Finite fields get their structure because we always know the value of infinity. If, for instance, we set the value of infinity to 12, the we can make a clock. We can count *0,1,2,3,4,5,6,7,8,9,10,11* and when we get to 12, we start again. Literally, and [mathematically](https://math.stackexchange.com/questions/2186685/every-finite-field-is-perfect), every finite field is perfect! 
\
Finite fields are useful in cryptography when we set the value of infinity to a large prime number. We claim a

### A Friendly Introduction to Combinatorics
A combination *n choose k* is the number of ways you can choose k elements from a total of n elements. For example, if you have 5 poker cards and you only need to choose 3, there are *5 choose 3* ways to pick the cards you want. You can find 

### A Technical Introduction to Combinatorial Finite Fields
