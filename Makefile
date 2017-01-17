all: utils
	g++ main.cpp utils.o -o main -Wall -ansi -pedantic -std=c++11

utils:
	g++ -c utils.cpp -o utils.o -Wall -ansi -pedantic -std=c++11

clean:
	rm -f main *.o
