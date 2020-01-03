//
//  ReallyLongInt.cpp
//  Project1.3
//

#include "ReallyLongInt.hpp"

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>
#include <string>
#include <climits>

using namespace std;



ReallyLongInt::ReallyLongInt()
{
    isNeg = false;
    unsigned *firsArr = new unsigned[1];
    firsArr[0] = 0;
    digits = firsArr;
    numDigits = 1;
}

void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) const
{
    int i = 0;
    int a = 0;
    unsigned begArraySize = xSize;
    
    while(x[i] == 0)
    {
        xSize--;
        a++;
        i++;
        
        if(xSize == 0)
        {
            x[0] = 99;
            xSize = 1;
        }

    }
    
    if(x[0] == 99)
    {
        x[0] = 0;
    }
    
    unsigned j = 0;
    for(unsigned k = i; k<begArraySize; k++)
    {
        x[j] = x[k];
        j++;
    }
    
}

ReallyLongInt::ReallyLongInt(const string& numStr)
{
    unsigned* pArray = new unsigned[numStr.size()];
    
    int j = 0;
    unsigned long numSize = numStr.size();
    
    for(unsigned i = 0; i<numSize; i++)
    {
        if(i == 0)
        {
            if(numStr[0] == '-')
            {
                isNeg = true;
                j++;
                numSize--;
            }
            else
            {
                isNeg = false;
            }
        }
        char c = numStr[j];
        pArray[i] = int(c) - 48;
        j++;
        
    }

    numDigits = int(numSize);

    removeLeadingZeros(pArray, numDigits);
    
    if(pArray[0] == 0)
    {
        isNeg = false;
        numDigits = 1;
    }

    digits = pArray;
    
}

ReallyLongInt::~ReallyLongInt()
{
    delete[] digits;
}

string ReallyLongInt::toString() const
{
    string longStr;
    
    unsigned long numSize = numDigits;
    
    for(unsigned i = 0; i<numSize; i++)
    {
        if(i==0)
        {
            if(isNeg == true)
            {
                longStr += '-';
            }
        }
        longStr += to_string(digits[i]);
    }
    
    return longStr;
}

ReallyLongInt::ReallyLongInt(long long num)
{
    if(num < 0)
    {
        isNeg = true;
        num = num*-1;
    }
    else
    {
        isNeg = false;
    }

    if(num == 0)
    {
        isNeg = false;
        unsigned* zeroArray = new unsigned[1];
        zeroArray[0] = 0;
        digits = zeroArray;
        numDigits = 1;
    }
    else
    {
        int loop = int(log10(num))+1;
        unsigned* pArray = new unsigned[loop];
        
        for(int i = loop; i>0; i--)
        {
            
            int backDigit = num%10;
            num = num/10;
            pArray[i-1] = backDigit;

        }
        
        digits = pArray;
        numDigits = loop;
    }
    

}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)
{
    isNeg = other.isNeg;
    numDigits = other.numDigits;

    unsigned* digits2 = new unsigned[other.numDigits];
    for(unsigned i = 0; i < numDigits; i++)
    {
        digits2[i] = other.digits[i];
    }
    digits = digits2;
    
}

ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg)
{
    removeLeadingZeros(digitsArr,arrSize);
    digits = digitsArr;
    numDigits = arrSize;

    if(digits[0] == 0)
    {
        isNeg = false;
    }
    
    this->isNeg = isNeg;

    //Need to test function by making public

}

bool ReallyLongInt::equal(const ReallyLongInt& other) const
{
    if(this->numDigits == other.numDigits)
    {
        if(this->isNeg == other.isNeg)
        {
            for(unsigned i = 0; i<this->numDigits; i++)
            {
                if(this->digits[i] != other.digits[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    return false;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
    if(this->numDigits > other.numDigits)
    {
        return true;
    }
    else if(this->numDigits < other.numDigits)
    {
        return false;
    }
    
    for(unsigned i = 0; i<this->numDigits; i++)
    {
        if(this->digits[i] > other.digits[i])
        {
            return true;
        }
        else if(this->digits[i] < other.digits[i])
        {
            return false;
        }
    }
    return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const
{
    if(this->isNeg == true)
    {
        if(other.isNeg == true)
        {
            return other.absGreater(*this);
        }
        else if(other.isNeg == false)
        {
            return false;
        }
        
    }
    else if(this->isNeg == false)
    {
        if(other.isNeg == true)
        {
            return true;

        }
        else if(other.isNeg == false)
        {
            return this->absGreater(other);
        }
    }

    return true;
}
    
ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const
{
    unsigned larger = max(this->numDigits, other.numDigits);
    unsigned smaller = min(this->numDigits, other.numDigits);
    
    unsigned* zeroArr = new unsigned[larger];
    unsigned* sumArr = new unsigned[larger+1];
    const unsigned* rli1 = this->digits;
    const unsigned* rli2 = other.digits;
    
    for(unsigned i =0; i<larger; i++)
    {
        zeroArr[i] = 0;
        sumArr[i] = 0;
    }
    sumArr[larger] = 0;
    
    if(this->numDigits != other.numDigits)
    {
        for(unsigned i =0; i<larger; i++)
        {
            zeroArr[i] = 0;
            sumArr[i] = 0;
        }
        sumArr[larger] = 0;
        
        for(unsigned j = 0; j<smaller; j++)
        {
            if(this->numDigits == smaller)
            {
                zeroArr[larger-(j+1)] = this->digits[smaller-(j+1)];
                
                if(j == smaller-1)
                {
                    rli1 = zeroArr;
                }
            }
            else if(other.numDigits == smaller)
            {
                zeroArr[larger-(j+1)] = other.digits[smaller-(j+1)];
                
                if(j == smaller-1)
                {
                    rli2 = zeroArr;
                }
            }
        }
    }

    
    unsigned b = 0;
    for(unsigned q = larger; q>0; q--)
    {
        unsigned a = rli1[q-1] + rli2[q-1] + b;
        if(a >= 10)
        {
            b = a/10;
        }
        else
        {
            b=0;
        }
        
        if(q == 1)
        {
            larger++;
            if(larger == 1)
            {
                sumArr[q-1] = a %10;
            }
            if(a>=10)
            {
                sumArr[q] = a%10;
                sumArr[q-1] = a / 10;
            }
            else
            {
                sumArr[q] = a % 10;
            }
           
        }
        else
        {
            sumArr[q] = a % 10;
        }
        
    }
    
    ReallyLongInt summation = ReallyLongInt(sumArr, larger, false);
    
    delete[] zeroArr;
    
    return summation;    
}
    
ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const
{
    if(this->isNeg == true)
    {
        if(other.isNeg == true)
        {
            return -(other.absAdd(*this));
        }
        return other.absSub(-*this);
    }
    else
    {
        if(other.isNeg == false)
        {
            return this->absAdd(other);
        }
        return this->absSub(-other);
    }
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const
{
    unsigned larger = max(this->numDigits, other.numDigits);
    unsigned smaller = min(this->numDigits, other.numDigits);
    
    unsigned* zeroArr = new unsigned[larger];
    unsigned* subArr = new unsigned[larger];
    const unsigned* rli1 = this->digits;
    const unsigned* rli2 = other.digits;
    
    for(unsigned i =0; i<larger; i++)
    {
        zeroArr[i] = 0;
    }
    
    if(this->numDigits != other.numDigits)
    {
        for(unsigned i =0; i<larger; i++)
        {
            zeroArr[i] = 0;
        }
        
        for(unsigned j = 0; j<smaller; j++)
        {
            if(this->numDigits == smaller)
            {
                zeroArr[larger-(j+1)] = this->digits[smaller-(j+1)];
                
                if(j == smaller-1)
                {
                    rli1 = zeroArr;
                }
            }
            else if(other.numDigits == smaller)
            {
                zeroArr[larger-(j+1)] = other.digits[smaller-(j+1)];
                
                if(j == smaller-1)
                {
                    rli2 = zeroArr;
                }
            }
        }
    }
    
    const unsigned* rli3 = rli1;
    const unsigned* rli4 = rli2;
    bool neg;
    
    
    if(this->greater(other)==false)
    {
        rli3 = rli2;
        rli4 = rli1;
        neg = true;
    }
    
    else
    {
        neg = false;
    }

    unsigned b = 0;
    for(int q = larger; q>0; q--)
    {
       

        int c;
        int a = (rli3[q-1]-b) - rli4[q-1];
        if(a < 0)
        {
            c = (10+rli3[q-1]-b)-rli4[q-1];
            b = 1;

        }
        else
        {
            c = (rli3[q-1]-b) - rli4[q-1];
            b=0;
        }
        
        subArr[q-1] = c;
        
    }
    
    ReallyLongInt difference = ReallyLongInt(subArr, larger, neg);
    
    delete[] zeroArr;
    

    return difference;
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
  
    
    if(this->isNeg == true)
    {
        if(other.isNeg == true)
        {
           // -other;
            return ((other*-1).absSub(*this*-1));
            
        }
        return -(this->absAdd(other));
    }
    else
    {
        if(other.isNeg == false)
        {
            return this->absSub(other);
        }
        return this->absAdd(other);
    }

}

ostream& operator<<(ostream& out, const ReallyLongInt& x)
{
    string str = x.toString();
    out << str;
    return out;
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{
    swap(other);
    return *this;
}

void ReallyLongInt::swap(ReallyLongInt other)
{
    const unsigned* digitCopy = this->digits;
    unsigned sizeCopy = this->numDigits;
    bool negCopy = this->isNeg;

    this->digits = other.digits;
    this->numDigits = other.numDigits;
    this->isNeg = other.isNeg;
    
    other.digits = digitCopy;
    other.numDigits = sizeCopy;
    other.isNeg = negCopy;
    
    
}

bool operator==(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.equal(y);
}

bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return !x.equal(y);
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.greater(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return y.greater(x);
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return (x.greater(y) || x.equal(y));
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return (y.greater(x) or y.equal(x));
}

void ReallyLongInt::flipSign()
{
    if(this->digits[0] == 0)
    {
        this->isNeg = false;
    }
    
    else if(this->isNeg == true)
    {
        this->isNeg = false;
    }
    else
    {
        this->isNeg = true;
    }
    
}

ReallyLongInt ReallyLongInt::operator-() const
{
    ReallyLongInt a = ReallyLongInt(*this);
    a.flipSign();
    return a;
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.sub(y);
}

ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other)
{
    *this = other + *this;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other)
{
    *this = *this - other;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator++()
{
    return *this+=1;
}

ReallyLongInt& ReallyLongInt::operator--()
{
    return *this-=1;
}

ReallyLongInt ReallyLongInt::operator++(int dummy)
{
    ReallyLongInt copied = ReallyLongInt(*this);
    *this += 1;
    return copied;
}

ReallyLongInt ReallyLongInt::operator--(int dummy)
{
    ReallyLongInt copied = ReallyLongInt(*this);
    *this -= 1;
    return copied;
}


ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
    unsigned prodSize = this->numDigits + other.numDigits;
    unsigned* prodArr = new unsigned[prodSize];
    
    for(unsigned k = 0; k < prodSize; k++)
    {
        prodArr[k] = 0;
    }

    for(int i = other.numDigits-1; i>=0; i--)
    {
        unsigned mult = 0;
        unsigned q = other.numDigits-1 - i;
        unsigned b  = 0;

        for(int j = this->numDigits-1; j>=0; j--)
        {
            q++;

            mult = other.digits[i] * this->digits[j];

            unsigned newDigit = prodArr[prodSize - q] + mult % 10;

            prodArr[prodSize - q] = newDigit % 10;

            if(newDigit >= 10)
            {
                b = newDigit/10;

            }
            else
            {
                b = 0;
            }
            
            prodArr[prodSize - q - 1] += mult / 10 + b;
            
        }
    }
   
    return ReallyLongInt(prodArr, prodSize, false);
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const
{
    if(this->isNeg == true)
    {
        if(other.isNeg == true)
        {
            return this->absMult(other);
        }
        return -(this->absMult(other));
    }
    else
    {
        if(other.isNeg == false)
        {
            return this->absMult(other);
        }
        return -(this->absMult(other));
    }
    return this->absMult(other);
}

ReallyLongInt operator*(const ReallyLongInt& x,const ReallyLongInt& y)
{
    return x.mult(y);
}

ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other)
{
    *this = this->mult(other);
    return *this;
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
    ReallyLongInt r(0);
    
    unsigned* qArray = new unsigned[this->numDigits];
    
    for(unsigned k = 0; k < this->numDigits; k++)
    {
        qArray[k] = 0;
    }
    
    for(unsigned i = 1; i<=this->numDigits; i++)
    {
        r *= 10;
        r += this->digits[i-1];
        
        unsigned d = 0;
        
        while(!other.absGreater(r))
        {
            r = r.absSub(other);
            d += 1;
        }
        
        qArray[i-1] = d;
        
    }
    ReallyLongInt q = ReallyLongInt(qArray, this->numDigits, false);
   

    remainder = r;
    quotient = q;
    
    
}


void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
    quotient.isNeg = false;
    remainder.isNeg = false;
    
    if(this->isNeg == true)
    {
        if(other.isNeg == true)
        {
            this->absDiv(other, quotient, remainder);
            remainder.flipSign();
        }
        else if(other.isNeg == false)
        {
            this->absDiv(other, quotient, remainder);
            quotient.flipSign();
            remainder.flipSign();
        }
    }
    else
    {
        if(other.isNeg == false)
        {
            this->absDiv(other, quotient, remainder);
        }
        else if(other.isNeg == true)
        {
            this->absDiv(other, quotient, remainder);
            quotient.flipSign();
        }
    }
}

ReallyLongInt operator/(const ReallyLongInt& x,const ReallyLongInt& y)
{
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    x.div(y, quotient, remainder);
    return quotient;
    
}

ReallyLongInt operator%(const ReallyLongInt& x,const ReallyLongInt& y)
{
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    x.div(y, quotient, remainder);
    return remainder;
}

ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other)
{
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    
    this->div(other, quotient, remainder);
    *this = quotient;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other)
{
    ReallyLongInt quotient;
    ReallyLongInt remainder;
    
    this->div(other, quotient, remainder);
    *this = remainder;
    return *this;
}

long long ReallyLongInt::toLongLong() const
{
    ReallyLongInt maxLong(LLONG_MAX);
    ReallyLongInt num = *this % (maxLong+1);
    
    long long finalLong = 0;
    long long ten = 1;
        
    for (int i = num.numDigits-1; i >= 0; i--)
    {
        finalLong += ten * num.digits[i];
        ten *= 10;
    }
   
    if(this->isNeg == true)
    {
        return finalLong * -1;
    }
    return finalLong;
    
}











































