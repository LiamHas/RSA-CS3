//
//  encrypt.cpp
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
    
    string e;
    string n;
    
    fin >> e;
    fin >> n;

    ifstream ffin(argv[2]);
    ofstream fout(argv[3]);
    
    ReallyLongInt e1(e);
    ReallyLongInt n1(n);

    char c;
    
    while(ffin.get(c))
    {
        fout << modPower(ReallyLongInt(c),e1,n1) << endl;
    }

}








