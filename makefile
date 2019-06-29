CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean run valgrind

all: debug

debug : CFLAGS += -g -O0
debug : gol

release : CFLAGS += -O3
release : gol

test: CFLAGS += -g -O0
test: mem_test valgrind

gol: main.o gol.o
	$(CC) main.o gol.o -o gol

mem_test: mem_test.o gol.o
	$(CC) mem_test.o gol.o -o mem_test

main.o: main.c gol.h
	$(CC) -c main.c

gol.o: gol.c gol.h
	$(CC) -c gol.c
	
mem_test.o: gol.c gol.h
	$(CC) -c mem_test.c
	
run: gol
	./gol

clean:
	rm *.o
	rm gol
	mem_test
	
valgrind: mem_test
	valgrind --leak-check=full --track-origins=yes ./mem_test
