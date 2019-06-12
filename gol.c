#include "gol.h"

#include <stdio.h>

static bool get_cell(struct gol *gol, int x, int y);

static int count_neighbors(struct gol *gol, int x, int y);

void gol_init(struct gol *gol)
{
	gol -> current_world = 0;
	
	// TODO: Poner el mundo a false
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			gol -> world[i][j][gol -> current_world] = 0;
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
			gol -> world[i][j][gol -> current_world] = glider[i][j];
		}
	};
}

void gol_print(struct gol *gol)
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
			printf("%c ", gol -> world[i][j][gol -> current_world]? 
					'#' : '.');
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct gol *gol)
{
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			int neighbors = gol_count_neighbors(gol, i, j);
			gol -> world[i][j][!gol -> current_world] =
				(gol -> world[i][j][gol->current_world] &&
				neighbors == 2) || neighbors == 3;
		}
	}
	
	gol -> current_world = !gol -> current_world;
}

static int count_neighbors(struct gol *gol, int x, int y)
{
	// Devuelve el número de vecinos
	int neighbors = 0;
	neighbors += gol_get_cell(gol, x - 1, y - 1);
	neighbors += gol_get_cell(gol, x - 1, y + 0);
	neighbors += gol_get_cell(gol, x - 1, y + 1);
				
	neighbors += gol_get_cell(gol, x + 0, y - 1);
	neighbors += gol_get_cell(gol, x + 0, y + 1);
				
	neighbors += gol_get_cell(gol, x + 1, y - 1);
	neighbors += gol_get_cell(gol, x + 1, y + 0);
	neighbors += gol_get_cell(gol, x + 1, y + 1);
	
	return neighbors;
}

static bool get_cell(struct gol *gol, int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	if ((x >= 0) && (x < ROWS) && (y >= 0) && (y < COLUMNS)) {
		return gol -> world[x][y][gol -> current_world];
	} else {
		return 0;	
	}
}
