all:
	g++ main.cpp -o main -Wall -ansi -pedantic

clean:
	rm -f main *.o
