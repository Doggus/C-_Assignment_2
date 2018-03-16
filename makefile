CC=g++
LIBS=-lm

main: main.o
	$(CC) -o main main.o -std=c++11

main.o: main.cpp
	$(CC) -c -o main.o main.cpp -std=c++11

run:
	./main
