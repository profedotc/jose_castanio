#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	bool world[ROWS][COLUMNS][2];
	// TODO: inicializa el mundo
	gol_init(world, i+1);
	
	do {
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(world, i%2);
		// TODO: Itera
		gol_step(world, i%2);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
