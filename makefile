CC=g++
LIBS=-lm

main: main.o
	$(CC) -o main main.o -std=c++11

main.o: main.cpp VolImage.o
	$(CC) -c -o main.o main.cpp -std=c++11

VolImage.o: VolImage.h VolImage.cpp
	$(CC) -c VolImage.cpp -std=c++11

run:
	./main
