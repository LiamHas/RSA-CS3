OPTS = -Wall

all: encrypt decrypt keygen

ReallyLongInt.o: ReallyLongInt.hpp ReallyLongInt.cpp
	g++ ${OPTS} -c ReallyLongInt.cpp

encrypt: encrypt.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o encrypt encrypt.cpp ReallyLongInt.o

decrypt: decrypt.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o decrypt decrypt.cpp ReallyLongInt.o

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.hpp numberTheory.tpp ReallyLongInt.cpp ReallyLongInt.hpp catch.hpp 
	g++ ${OPTS} -o numberTheory_TEST numberTheory_TEST.cpp ReallyLongInt.cpp

keygen: keygen.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o keygen keygen.cpp ReallyLongInt.o

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.cpp ReallyLongInt.hpp numberTheory.tpp numberTheory.hpp catch.hpp 
	g++ ${OPTS} -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp

tests: numberTheory_TEST ReallyLongInt_TEST