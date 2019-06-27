CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean run

all: debug

debug : CFLAGS += -g -O0
debug : gol

release : CFLAGS += -O3
release : gol

gol: main.o gol.o
	$(CC) main.o gol.o -o gol

main.o: main.c gol.h
	$(CC) -c main.c

gol.o: gol.c gol.h
	$(CC) -c gol.c
	
run: gol
	./gol

clean:
	rm *.o
	rm gol
