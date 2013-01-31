CC=g++

all: 81Driver

81Driver: CalcDerivative.o
	$(CC) CalcDerivative.o 81_chall.cpp -o 81Driver -std=c++11

CalcDerivative.o:
	$(CC) -c CalcDerivative.cpp -std=c++11

clean:
	rm CalcDerivative.o
	rm 81Driver
