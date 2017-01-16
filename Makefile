all:
	g++ main.cpp -o main -Wall -ansi -pedantic -std=c++11

clean:
	rm -f main *.o
