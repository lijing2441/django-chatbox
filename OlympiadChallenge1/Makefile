CC=g++

all: detonate

detonate: Solver.o
	$(CC) Solver.o main.cpp -o detonate -std=c++11 -O2

Solver.o:
	$(CC) -c Solver.cpp -std=c++11 -O2

clean:
	rm Solver.o detonate
