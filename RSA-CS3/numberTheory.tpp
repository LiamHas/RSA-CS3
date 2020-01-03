//
//  numberTheoryTPP.cpp
//  Project1.4
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>

using namespace std;

template <class X>
bool isPrime(const X& num)
{
    if(num == 0 or num == 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    
    for(unsigned i=2; i<num/2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <class X>
X modPower(const X& base, const X& exponent, const X& modulus)
{

    if(exponent == 0)
    {
        return 1;
    }

    X rec = modPower(base,(exponent/2), modulus);

    if(exponent%2 == 0)
    {
        return rec * rec % modulus;
    }
    else
    {
        return (base*rec) % modulus * rec % modulus;
    }
}

template <class X>
X extendedEuclid(const X& a, const X& b, X* x, X* y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        
        return a;
    }
    else
    {
        X x1;
        X y1;
        
        X d = extendedEuclid(b, a % b, &x1, &y1);
        
        *x = y1;
        *y = x1 - y1 * (a/b);
        
        return d;
    }
}



















































