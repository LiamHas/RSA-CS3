//
//  ReallyLongInt_TEST.cpp
//  Project1.3
//


#include <stdio.h>
#include <climits>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing ReallyLongInt class")
{
    SECTION("Testing toString and the ReallyLongInt class construction")
    {
        ReallyLongInt* rli = new ReallyLongInt("1234");
        REQUIRE(rli->toString() == "1234");
        
        ReallyLongInt* rli2 = new ReallyLongInt("-0001234");
        REQUIRE(rli2->toString() == "-1234");

        ReallyLongInt* rli3 = new ReallyLongInt("000000");
        REQUIRE(rli3->toString() == "0");

        ReallyLongInt* rli4 = new ReallyLongInt("-000000");
        REQUIRE(rli4->toString() == "0");
    }
    
    SECTION("Testing ReallyLongInt(long long num)")
    {
        ReallyLongInt* rli5 = new ReallyLongInt(123456789);
        REQUIRE(rli5->toString() == "123456789");
        
        ReallyLongInt* rli6 = new ReallyLongInt(10000);
        REQUIRE(rli6->toString() == "10000");

        ReallyLongInt* rli7 = new ReallyLongInt(-1234);
        REQUIRE(rli7->toString() == "-1234");

        ReallyLongInt* rli8 = new ReallyLongInt(00000);
        REQUIRE(rli8->toString() == "0");
    }
    
    SECTION("Testing ReallyLongInt(ReallyLongInt &other)")
    {
        ReallyLongInt* rliA = new ReallyLongInt(12345);
        ReallyLongInt* rliB = new ReallyLongInt(*rliA);
        
        REQUIRE(rliA->equal(*rliB));
    }
    
    SECTION("Testing ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg)")
    {
        //CAN ONLY TEST WHEN MADE PUBLIC
        /*
        unsigned* testArr = new unsigned[5];
        for(int i = 0; i<5; i++)
        {
            testArr[i] = i;
        }
        ReallyLongInt* rli9 = new ReallyLongInt(testArr, 5, true);
        REQUIRE(rli9->toString() == "-1234");

        unsigned* testArr1 = new unsigned[5];
        for(int i = 0; i<5; i++)
        {
            testArr1[i] = 0;
        }
        ReallyLongInt* rli10 = new ReallyLongInt(testArr1, 5, true);
        REQUIRE(rli10->toString() == "0");

        unsigned* testArr2 = new unsigned[5];
        testArr2[0] = 0;
        testArr2[1] = 0;
        testArr2[2] = 9;
        ReallyLongInt* rli11 = new ReallyLongInt(testArr2, 3, false);
        REQUIRE(rli11->toString() == "9");
        */
    }
    
    SECTION("Testing equal")
    {
        
        ReallyLongInt* rli12 = new ReallyLongInt("000100234");
        ReallyLongInt* rli13 = new ReallyLongInt("000000100234");
        REQUIRE(rli12->equal(*rli13) == true);
        
        ReallyLongInt* rli14 = new ReallyLongInt("-0000000000000");
        ReallyLongInt* rli15 = new ReallyLongInt(000000);
        REQUIRE(rli14->equal(*rli15) == true);
        
        ReallyLongInt* rli16 = new ReallyLongInt("00010900");
        ReallyLongInt* rli17 = new ReallyLongInt("00189403");
        REQUIRE(rli16->equal(*rli17) == false);
        
        ReallyLongInt* rli18 = new ReallyLongInt("-12345");
        ReallyLongInt* rli19 = new ReallyLongInt(-23456);
        REQUIRE(rli18->equal(*rli19) == false);
        
        ReallyLongInt* rli20 = new ReallyLongInt("-12345");
        ReallyLongInt* rli21 = new ReallyLongInt(12345);
        REQUIRE(rli20->equal(*rli21) == false);
    }
    
    SECTION("Testing absGreater and greater")
    {
        ReallyLongInt* rli22 = new ReallyLongInt("-12345");
        ReallyLongInt* rli23 = new ReallyLongInt(12345);
        REQUIRE(rli22->greater(*rli23) == false);
        REQUIRE(rli23->greater(*rli22) == true);

        ReallyLongInt* rli24 = new ReallyLongInt("-00009999");
        ReallyLongInt* rli25 = new ReallyLongInt("0000009");
        REQUIRE(rli24->greater(*rli25) == false);
        REQUIRE(rli25->greater(*rli24) == true);
        
        ReallyLongInt* rli26 = new ReallyLongInt("-12345");
        ReallyLongInt* rli27 = new ReallyLongInt("-123456");
        REQUIRE(rli26->greater(*rli27) == true);
        REQUIRE(rli27->greater(*rli26) == false);
        
        ReallyLongInt* rli28 = new ReallyLongInt("00012345678");
        ReallyLongInt* rli29 = new ReallyLongInt(-1);
        REQUIRE(rli28->greater(*rli29) == true);
        REQUIRE(rli29->greater(*rli28) == false);
        
        ReallyLongInt* rlip = new ReallyLongInt("1234");
        ReallyLongInt* rliq = new ReallyLongInt("1235");
        REQUIRE(rlip->greater(*rliq) == false);
        REQUIRE(rliq->greater(*rlip) == true);
        
        ReallyLongInt* rliw = new ReallyLongInt(-51);
        ReallyLongInt* rlix = new ReallyLongInt(-51);
        ReallyLongInt* rliy = new ReallyLongInt(55);
        ReallyLongInt* rliz = new ReallyLongInt(54);

        REQUIRE(rlix->greater(*rliw) == false);
        REQUIRE(rliy->greater(*rliz) == true);
        REQUIRE(rliz->greater(*rliy) == false);

    }
    
    SECTION("Testing add and absAdd")
    {
        ReallyLongInt* rli30 = new ReallyLongInt("954");
        ReallyLongInt* rli31 = new ReallyLongInt("60");
        ReallyLongInt added = rli30->add(*rli31);
        REQUIRE(added.toString() == "1014");

        ReallyLongInt* rli32 = new ReallyLongInt("999999");
        ReallyLongInt* rli33 = new ReallyLongInt("999999");
        ReallyLongInt added2 = rli32->add(*rli33);
        REQUIRE(added2.toString() == "1999998");

        ReallyLongInt* rli34 = new ReallyLongInt("00000001");
        ReallyLongInt* rli35 = new ReallyLongInt("1");
        ReallyLongInt added3 = rli34->add(*rli35);
        REQUIRE(added3.toString() == "2");
        
        ReallyLongInt* rli36 = new ReallyLongInt("199");
        ReallyLongInt* rli37 = new ReallyLongInt("2");
        ReallyLongInt added4 = rli36->add(*rli37);
        REQUIRE(added4.toString() == "201");
        
        ReallyLongInt* rli38 = new ReallyLongInt("5");
        ReallyLongInt* rli39 = new ReallyLongInt("6");
        ReallyLongInt added5 = rli38->add(*rli39);
        REQUIRE(added5.toString() == "11");
    }
    
    SECTION("Testing sub and absSub")
    {
        ReallyLongInt* rli36 = new ReallyLongInt("001234");
        ReallyLongInt* rli37 = new ReallyLongInt("000999");
        ReallyLongInt* rli38 = new ReallyLongInt("00000");
        ReallyLongInt* rli39 = new ReallyLongInt("11");
        ReallyLongInt* rli40 = new ReallyLongInt("2");

        ReallyLongInt subbed = rli36->sub(*rli37);
        ReallyLongInt subbed1 = rli37->sub(*rli36);
        ReallyLongInt subbed2 = rli37->sub(*rli37);
        ReallyLongInt subbed3 = rli38->sub(*rli37);
        ReallyLongInt subbed4 = rli39->sub(*rli40);


        REQUIRE(subbed.toString() == "235");
        REQUIRE(subbed1.toString() == "-235");
        REQUIRE(subbed2.toString() == "0");
        REQUIRE(subbed3.toString() == "-999");
        REQUIRE(subbed4.toString() == "9");
        
        //TESTs after making add consider negatives
        ReallyLongInt a(10);
        ReallyLongInt b(15);
        ReallyLongInt c(-10);
        ReallyLongInt d(-15);
        
        REQUIRE(a.add(b) == 25);
        REQUIRE(c.add(b) == 5);
        REQUIRE(c.add(d) == -25);
        REQUIRE(a.add(d) == -5);

        REQUIRE(a.sub(b) == -5);
        REQUIRE(c.sub(b) == -25);
        REQUIRE(c.sub(d) == 5);
        REQUIRE(a.sub(d) == 25);
        
        REQUIRE(b.sub(c) == 25);
        REQUIRE(d.sub(c) == -5);
        
    }
    
    SECTION("Testing output stream")
    {
        ReallyLongInt* rli41 = new ReallyLongInt("001234");
        ReallyLongInt* rli42 = new ReallyLongInt("-0123456789");

        //cout<<*rli41<<endl; //Testing printing to terminal
        //ofstream outputFile("outputFile.txt");
        //outputFile <<*rli42 << endl;
        
    }
    
    SECTION("Testing assignment overload and swap function")
    {
        ReallyLongInt x(10);
        REQUIRE(x == 10);
        
        ReallyLongInt y;
        y = x;
        REQUIRE(y == 10);


        y = -58;
        REQUIRE(y == -58);


        ReallyLongInt z("10");
        REQUIRE(z == 10);


        y = string("123456789");
        REQUIRE(y == 123456789);
    }
    
    SECTION("Testing comparison operators")
    {
        ReallyLongInt a(10);
        ReallyLongInt b(-10);
        ReallyLongInt c(10);
        ReallyLongInt d(5);

        REQUIRE(a == c);
        REQUIRE((a == b) == false);
        
        REQUIRE((a != c) == false);
        REQUIRE(a != b);
        
        REQUIRE(a > d);
        REQUIRE((b > d) == false);
        
        REQUIRE(d < a);
        REQUIRE((d < b) == false);

        REQUIRE(a >= c);
        REQUIRE(a >= d);
        REQUIRE(c >= b);
        REQUIRE((d >= a) == false);
        
        REQUIRE(a <= c);
        REQUIRE((a <= d) == false);
        REQUIRE((c <= b) == false);
        REQUIRE(d <= a);
    }
    
    SECTION("Testing flipSign and - operator overload")
    {
        ReallyLongInt rli43(123456);
        ReallyLongInt rli44(0);
        ReallyLongInt rli45("-0001234");

        REQUIRE(-rli43 == -123456);
        REQUIRE(-rli44 == 0);
        REQUIRE(-rli45 == 1234);
        
    }
    
    SECTION("Testing +, -, +=, -=, ++x, --x, x++, x--")
    {
        ReallyLongInt rli46(9);
        ReallyLongInt rli47(19);
        
        REQUIRE((rli46 + rli47) == 28);
        REQUIRE((rli46 - rli47) == -10);
        REQUIRE((rli47 - rli46) == 10);

        REQUIRE((rli47 += rli46) == 28);
        REQUIRE((rli47 -= rli46) == 19);
        
        REQUIRE((++rli47) == 20);
        REQUIRE((++rli46) == 10);
        
        REQUIRE((--rli47) == 19);
        REQUIRE((--rli46) == 9);
      

        ReallyLongInt rli48(9);
        ReallyLongInt rli49(19);
        
        REQUIRE((rli48++) == 9);
        REQUIRE((rli49++) == 19);
        REQUIRE((rli48--) == 10);
        REQUIRE((rli49--) == 20);

    }
    
    SECTION("Testing mult and absMult")
    {
        ReallyLongInt rli50(56);
        ReallyLongInt rli51(34);
        ReallyLongInt rli52 = rli50.mult(rli51);
        REQUIRE(rli52 == 1904);
        
        ReallyLongInt rli53(14);
        ReallyLongInt rli54(109);
        ReallyLongInt rli55 = rli53.mult(rli54);
        REQUIRE(rli55 == 1526);
        
        ReallyLongInt rli56(0);
        ReallyLongInt rli57(109);
        ReallyLongInt rli58 = rli56.mult(rli57);
        REQUIRE(rli58 == 0);
        
        ReallyLongInt rli59(99);
        ReallyLongInt rli60(9999);
        ReallyLongInt rli61 = rli59.mult(rli60);
        REQUIRE(rli61 == 989901);
        
        ReallyLongInt rli62(-10);
        ReallyLongInt rli63(90);
        ReallyLongInt rli64 = rli62.mult(rli63);
        ReallyLongInt rli65 = rli63.mult(rli62);
        REQUIRE(rli64 == -900);
        REQUIRE(rli65 == -900);

        ReallyLongInt rli66(-10);
        ReallyLongInt rli67(-90);
        ReallyLongInt rli68 = rli66.mult(rli67);
        ReallyLongInt rli69 = rli67.mult(rli66);
        REQUIRE(rli68 == 900);
        REQUIRE(rli69 == 900);
       
        ReallyLongInt rli70(10);
        ReallyLongInt rli71(-90);
        ReallyLongInt rli72 = rli70.mult(rli71);
        ReallyLongInt rli73 = rli71.mult(rli70);
        REQUIRE(rli72 == -900);
        REQUIRE(rli73 == -900);
        
        ReallyLongInt rli74(10);
        ReallyLongInt rli75(90);
        ReallyLongInt rli76 = rli74.mult(rli75);
        ReallyLongInt rli77 = rli75.mult(rli74);
        REQUIRE(rli76 == 900);
        REQUIRE(rli77 == 900);

    }
    
    SECTION("Testing * and *= overloaded operators")
    {
        ReallyLongInt rli78(10);
        ReallyLongInt rli79(-90);
        ReallyLongInt rli80 = rli78 * rli79;
        REQUIRE(rli80 == -900);

        ReallyLongInt rli81(4);
        for(int i = 1; i<5; i++)
        {
            rli81 *= i;
        }
        REQUIRE(rli81 == 96);
    }
    
    SECTION("Testing div and absDiv")
    {
        ReallyLongInt rli82(123);
        ReallyLongInt rli83(2);
        
        ReallyLongInt quotient;
        ReallyLongInt remainder;
        rli82.div(rli83, quotient, remainder);
        REQUIRE(quotient == 61);
        REQUIRE(remainder == 1);

        ReallyLongInt rli84(-123);
        ReallyLongInt rli85(2);

        ReallyLongInt quotient1;
        ReallyLongInt remainder1;
        
        rli84.div(rli85, quotient1, remainder1);
        REQUIRE(quotient1 == -61);
        REQUIRE(remainder1 == -1);
        
        ReallyLongInt rli86(-123);
        ReallyLongInt rli87(-2);
        
        ReallyLongInt quotient2;
        ReallyLongInt remainder2;
        
        rli86.div(rli87, quotient2, remainder2);
        REQUIRE(quotient2 == 61);
        REQUIRE(remainder2 == -1);
        
        ReallyLongInt rli88(123);
        ReallyLongInt rli89(-2);
        
        ReallyLongInt quotient3;
        ReallyLongInt remainder3;
        
        rli88.div(rli89, quotient3, remainder3);
        REQUIRE(quotient3 == -61);
        REQUIRE(remainder3 == 1);
        
    }
    
    SECTION("Testing /, /=, %, %= overloaded operators")
    {
        ReallyLongInt rli90(100);
        ReallyLongInt rli91(9);
        
        REQUIRE((rli90/rli91) == 11);
        REQUIRE((rli90%rli91) == 1);

        ReallyLongInt rli92(100);
        
        for(int i = 1; i<5; i++)
        {
            rli92 /= i;
        }
        REQUIRE(rli92 == 4);
        
        ReallyLongInt rli95(2);
        
        rli92 /= rli95;
        REQUIRE(rli92 == 2);
        
        
        ReallyLongInt rli93(99);
        ReallyLongInt rli94(50);
        rli93 %= 50;
        REQUIRE(rli93 == 49);
        
        ReallyLongInt rli96(5);
        rli93 %= 5;
        REQUIRE(rli93 == 4);
        
        ReallyLongInt rliTest(5);
        ReallyLongInt rliTest2(-10);
        
        REQUIRE((rliTest / rliTest2) == 0);

    }
    SECTION("Testing toLongLong")
    {
        ReallyLongInt rli97(12345);
        long long a = rli97.toLongLong();
        REQUIRE(a == 12345);
        
        ReallyLongInt rli98(-12345);
        long long b = rli98.toLongLong();
        REQUIRE(b == -12345);
        
        ReallyLongInt rli99(0);
        long long c = rli99.toLongLong();
        REQUIRE(c == 0);
        
        ReallyLongInt rli100(100001);
        long long d = rli100.toLongLong();
        REQUIRE(d == 100001);
        
        ReallyLongInt rli101(LLONG_MAX);
        long long e = rli101.toLongLong();
        REQUIRE(e == LLONG_MAX);
    }
    
}












































