Liam Hasandjekaj
CPS 222 Project 1

Files Submitted: 
catch.hpp 
decrypt.cpp 
encrypt.cpp 
keygen.cpp 
Makefile
numberTheory_TEST.cpp
numberTheory.hpp
numberTheory.tpp
ReallyLongInt_TEST.cpp
ReallyLongInt.cpp
ReallyLongInt.hpp
readme.txt
Project 1 Final Coversheet - RSA

This project contains several files relating to an RSA encryption and decryption method. The command 'make all' will compile all files necessary for encryption and decryption in the project, or you may compile according to the following directions.

---encrypt---
To compile: make encrypt
To run: ./encrypt <public key file> <plaintext file to encrypt> <output file for encryption>
Description:

The encrypt program receives plaintext, encrypts the text character by character  using a modPower function and then writes that encrypted text to a given output file. The program utilizes a modPower function which generates particular numbers based on the ascii value of the inputted character. When running the program, give the <public key file> generated in keygen, then the <plaintext file> that you want encrypted, followed by the <output file> for the encrypted text to be written to.

---decrypt---
To compile: make decrypt
To run: ./decrypt <private key file> <encrypted file> <output file for decryption>
Description:

The decrypt program receives a file with encrypted text and decrypts the text character by character using the same modPower method as in encrypt. The decrypted text is then written to a given output file, which will be the same as the plaintext passed into the encrypt function. When running the program, give the <private key file> generated in keygen, followed by the <encrypted file> which is an output of encrypt, and then an <output file> for the decrypted text to be written to.


---keygen---
To compile: make keygen
To run: ./keygen <prime number> <different prime number> <output file for public key> <output file for private key>
Description:

The keygen program contains an algorithmic function that creates and writes a public and private key which can be used for encrypting and decrypting a plaintext message. The program utilizes the extended Euclidean algorithm and a function isPrime() that validates if a number is prime or not. When running the program, give two different <prime> <prime> numbers, who's product is greater than 256, followed by an <output file> for the public key and an <output file> for a private key.




