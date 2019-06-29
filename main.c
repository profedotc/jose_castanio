#include <stdio.h>
#include <stdlib.h>

#include "gol.h"

int main()
{
	int i = 0;
	struct gol gol;
	
	gol_alloc(&gol, ROWS, COLUMNS);
	gol_init(&gol, ROWS, COLUMNS);
	
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&gol, ROWS, COLUMNS); // Imprime el mundo
		gol_step(&gol, ROWS, COLUMNS); // Itera
	} while (getchar() != 'q');

	gol_free(&gol, COLUMNS);

	return EXIT_SUCCESS;
}
