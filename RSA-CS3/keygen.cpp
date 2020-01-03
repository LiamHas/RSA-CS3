//
//  keygen.cpp
//  Project1CP2
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ReallyLongInt p = ReallyLongInt(argv[1]);
    ReallyLongInt q = ReallyLongInt(argv[2]);

    ofstream pblc(argv[3]);
    ofstream prvt(argv[4]);
        
    if(p > 100000 or q > 100000)
    {
        cout<< "The numbers inputed are > 100,000 so primality cannot be verified"<<endl;
    }
    
    else if (isPrime(p) == false or isPrime(q) == false)
    {
        cout << "The numbers inputed are not prime. Please provide prime numbers" << endl;
        return 1;
    }
    
    
    ReallyLongInt n = p*q;
    ReallyLongInt t = (p-1)*(q-1);
    
    for(ReallyLongInt e = 2; e<t; e++)
    {
        ReallyLongInt pe;
        ReallyLongInt pt;
        
        if(extendedEuclid(e,t,&pe,&pt) == 1)
        {
            ReallyLongInt d = pe;
            ReallyLongInt* pd = &d;
            
            if((e*d)%t == 1)
            {
                if(d<0)
                {
                    d = d + t;
                }
                
                pblc << e << " " << n << endl;
                prvt << *pd << " " << n << endl;
                return 0;
                    
            }
        }
    }
}










