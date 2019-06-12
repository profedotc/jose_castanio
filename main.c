#include <stdio.h>
#include <stdlib.h>

#include "gol.h"

int main()
{
	int i = 0;
	struct gol gol;
	
	gol_init(&gol);
	
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&gol); // Imprime el mundo
		gol_step(&gol); // Itera
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
