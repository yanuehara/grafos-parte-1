CFLAGS = -Wall -ansi -pedantic

all: utils
	g++ main.cpp utils.o -o main $(CFLAGS)

utils:
	g++ -c utils.cpp -o utils.o $(CFLAGS)

clean:
	rm -f main *.o
