//
//  decrypt.cpp
//  Project 1: RSA


#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>

#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ifstream fin(argv[1]);
    string d;
    string n;
    
    fin >> d;
    fin >> n;
    
    ifstream ffin(argv[2]);
    ofstream fout(argv[3]);
    
    ReallyLongInt d1(d);
    ReallyLongInt n1(n);
    
    unsigned long y;
    ffin >> y;
    ReallyLongInt x;
    ReallyLongInt y1(y);

    while(!ffin.eof())
    {

        x = modPower(y1,d1,n1);
        long long x1 = x.toLongLong();
        char xChar = char(x1);
        fout << xChar;
        ffin >> y;
        y1 = ReallyLongInt(y);
        
    }
}











