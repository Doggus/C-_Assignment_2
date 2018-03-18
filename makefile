CC=g++
LIBS=-lm

main: main.o VolImage.o
	$(CC) -o main main.o VolImage.o -std=c++11

main.o: main.cpp
	$(CC) -c main.cpp -std=c++11

VolImage.o: VolImage.h VolImage.cpp
	$(CC) -c VolImage.cpp -std=c++11

run:
	./main
