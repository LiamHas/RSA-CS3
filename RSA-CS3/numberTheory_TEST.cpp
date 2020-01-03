//
//  numberTheory_TEST.cpp
//  Project 1: RSA
//

#define CATCH_CONFIG_MAIN
#include <stdio.h>
#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("Testing funcitons")
{
    SECTION("Testing modPower")
    {
         REQUIRE(modPower(2ll,2ll,3ll) == 1ll);
         REQUIRE(modPower(2ll,3ll,3ll) == 2ll);
         REQUIRE(modPower(12ll,12ll,123ll) == 66ll);
         REQUIRE(modPower(10ll,19ll,1019ll) == 776ll);
         REQUIRE(modPower(12345ll,1234567ll,123ll) == 66ll);
         REQUIRE(modPower(12345ll,1234567ll,123456789ll) == 100842075ll);
         REQUIRE(modPower(12345ll,1234567ll,12345ll) == 0ll);
         //REQUIRE(modPower(12345,123456789,1234567891011));
         REQUIRE(modPower(0ll,12345ll,15ll) == 0ll);
         REQUIRE(modPower(12345ll,0ll,15ll) == 1ll);

    }
    SECTION("Testing isPrime")
    {
        REQUIRE(isPrime(0ull) == false);
        REQUIRE(isPrime(1ull) == false);
        REQUIRE(isPrime(2ull) == true);
        REQUIRE(isPrime(3ull) == true);
        REQUIRE(isPrime(50ull) == false);
        REQUIRE(isPrime(100ull) == false);
        REQUIRE(isPrime(101ull) == true);
    }
    SECTION("Testing extendedEuclid")
    {
        
        long long a = 99;
        long long b = 78;
        
        long long px;
        long long py;
        
        
        REQUIRE(extendedEuclid(99ll, 78ll, &px, &py) == 3);
        REQUIRE(99ll*px + 78ll*py == 3ll);

        REQUIRE(extendedEuclid(101ll, 65ll, &px, &py) == 1ll);
        REQUIRE(101ll*px + 65ll*py == 1ll);
        
        REQUIRE(extendedEuclid(12ll, 144ll, &px, &py) == 12ll);
        REQUIRE(12ll*px + 144ll*py == 12ll);

        REQUIRE(extendedEuclid(70ll, 0ll, &px, &py) == 70ll);
        REQUIRE(70ll*px + 0ll*py == 70ll);

        REQUIRE(extendedEuclid(568ll, 1984ll, &px, &py) == 8ll);
        REQUIRE(568ll*px + 1984ll*py == 8ll);

    }
    SECTION("Testing with ReallyLongInts")
    {
        
         REQUIRE(modPower(12ll,12ll,123ll) == 66ll);
        
        ReallyLongInt a1(12);
        ReallyLongInt a2(123);
        ReallyLongInt a3(66);
        REQUIRE(modPower(a1,a1,a2) == a3);

        
        
        ReallyLongInt a(12345);
        ReallyLongInt b(1234567);
        ReallyLongInt c(123456789);
        ReallyLongInt d(100842075);
        ReallyLongInt d2(1234567891011);
        ReallyLongInt ans(519170861217);
        REQUIRE(modPower(a,c,d2) == ans);
    
        ReallyLongInt e(0);
        ReallyLongInt f(1);
        ReallyLongInt g(2);
        ReallyLongInt h(3);
        REQUIRE(isPrime(ReallyLongInt(50)) == false);
        REQUIRE(isPrime(ReallyLongInt(100)) == false);
        REQUIRE(isPrime(ReallyLongInt(101)) == true);
        
        REQUIRE(isPrime(e) == false);
        REQUIRE(isPrime(f) == false);
        REQUIRE(isPrime(g) == true);
        REQUIRE(isPrime(h) == true);
        
        
        ReallyLongInt px;
        ReallyLongInt py;
        
        ReallyLongInt k(101);
        ReallyLongInt l(65);
        ReallyLongInt m(1);
        REQUIRE(extendedEuclid(k, l, &px, &py) == m);
        REQUIRE(k*px + l*py == m);
        
        
        ReallyLongInt i(99);
        ReallyLongInt j(78);
        REQUIRE(extendedEuclid(i, j, &px, &py) == 3);
        REQUIRE(i*px + j*py == 3);
        
        REQUIRE(extendedEuclid(ReallyLongInt(568), ReallyLongInt(1984), &px, &py) == 8);
        REQUIRE(ReallyLongInt(568)*px + ReallyLongInt(1984)*py == 8);

    
    }
        
}

















