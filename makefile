.PHONY: all clean

all: gol

gol: main.o gol.o
	gcc main.o gol.o -o gol
	
main.o: main.c
	gcc -c main.c
	
gol.o: gol.h gol.c
	gcc -c gol.c

clean:
	rm *.o
	rm gol
