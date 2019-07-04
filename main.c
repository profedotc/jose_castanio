#include <stdio.h>
#include <stdlib.h>

#include "gol.h"

#define ROWS 15
#define COLUMNS 20

int main()
{
	int i = 0;
	struct gol gol;
	
	gol_alloc(&gol, ROWS, COLUMNS);
	gol_init(&gol);
	
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&gol); // Imprime el mundo
		gol_step(&gol); // Itera
	} while (getchar() != 'q');

	gol_free(&gol);

	return EXIT_SUCCESS;
}
