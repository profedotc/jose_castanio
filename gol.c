#include <stdio.h>
#include <stdbool.h>
#include "gol.h"

void gol_init(bool world[ROWS][COLUMNS][2], int z)
{
	// TODO: Poner el mundo a false
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			world[i][j][0] = 0;
			world[i][j][1] = 0;
		}
	}

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	char glider[3][3] = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
	};
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			world[i][j][z] = glider[i][j];
		}
	};
}

void gol_print(bool world[ROWS][COLUMNS][2], int z)
{
	// TODO: Imprimir el mundo por consola. Sugerencia:
	/*
	 *     . # . . . . . . . .
	 *     . . # . . . . . . .
	 *     # # # . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 */
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("%c ", world[i][j][z]? '#' : '.');
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(bool world[ROWS][COLUMNS][2], int z)
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			int neighbors = gol_count_neighbors(world, i, j, z);
			if (world[i][j][z]) {
				world[i][j][!z] = (neighbors == 3) || 
								  (neighbors == 2);
			} else {
				world[i][j][!z] = (neighbors == 3);
			}
		}
	}
}

int gol_count_neighbors(bool world[ROWS][COLUMNS][2], int x, int y, int z)
{
	// Devuelve el número de vecinos
	int neighbors = 0;
	neighbors += gol_get_cell(world, x - 1, y - 1, z);
	neighbors += gol_get_cell(world, x - 1, y + 0, z);
	neighbors += gol_get_cell(world, x - 1, y + 1, z);
				
	neighbors += gol_get_cell(world, x + 0, y - 1, z);
	neighbors += gol_get_cell(world, x + 0, y + 1, z);
				
	neighbors += gol_get_cell(world, x + 1, y - 1, z);
	neighbors += gol_get_cell(world, x + 1, y + 0, z);
	neighbors += gol_get_cell(world, x + 1, y + 1, z);
	
	return neighbors;
}

bool gol_get_cell(bool world[ROWS][COLUMNS][2], int x, int y, int z)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	if ((x >= 0) && (x < ROWS) && (y >= 0) && (y < COLUMNS)) {
		return world[x][y][z];
	} else {
		return 0;	
	}
}
