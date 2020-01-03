//
//  numberTheory.hpp
//  Project 1: RSA
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>

#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

template <class X>
bool isPrime(const X& num);

template <class X>
X modPower(const X& base, const X& exponent, const X& modulus);

template <class X>
X extendedEuclid(const X& a, const X& b, X* x, X* y);

#include "numberTheory.tpp"

#endif /* numberTheory_hpp */

