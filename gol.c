#include "gol.h"

#include <stdio.h>
#include <stdlib.h>

enum state{ CURRENT, NEXT };

static bool get_cell(const struct gol *gol, int x, int y, int rows, int columns);
static int count_neighbors(const struct gol *gol, int x, int y, int rows, int columns);
static bool rule(struct gol *gol, int x, int y, int rows, int columns);

void gol_alloc(struct gol *gol, int rows, int columns)
{
	gol -> worlds[CURRENT] = (bool **)malloc(rows * sizeof(bool *));
	gol -> worlds[NEXT] = (bool **)malloc(rows * sizeof(bool *));
	
	for (int i = 0; i < columns; i++){
		gol -> worlds[CURRENT][i] = (bool *)malloc(columns * sizeof(bool));
		gol -> worlds[NEXT][i] = (bool *)malloc(columns * sizeof(bool));
	}
}

void gol_free(struct gol *gol, int columns)
{
	for (int i = 0; i < columns; i++){
		free(gol -> worlds[NEXT][i]);
		free(gol -> worlds[CURRENT][i]);
	}
	
	free(gol -> worlds[NEXT]);
	free(gol -> worlds[CURRENT]);
}

void gol_init(struct gol *gol, int rows, int columns)
{
	// TODO: Poner el mundo a false
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			gol -> worlds[CURRENT][i][j] = 0;
			gol -> worlds[NEXT][i][j] = 0;
		}
	}

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	gol -> worlds[CURRENT][0][0] = 0;
	gol -> worlds[CURRENT][0][1] = 1;
	gol -> worlds[CURRENT][0][2] = 0;
	
	gol -> worlds[CURRENT][1][0] = 0;
	gol -> worlds[CURRENT][1][1] = 0;
	gol -> worlds[CURRENT][1][2] = 1;
	
	gol -> worlds[CURRENT][2][0] = 1;
	gol -> worlds[CURRENT][2][1] = 1;
	gol -> worlds[CURRENT][2][2] = 1;
}

void gol_print(const struct gol *gol, int rows, int columns)
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
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			printf("%c ", gol -> worlds[CURRENT][i][j]? 
					'#' : '.');
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct gol *gol, int rows, int columns)
{
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			gol -> worlds[NEXT][i][j] = rule(gol, i, j, rows, columns);
		}
	}
	
	bool *aux = gol -> worlds[NEXT];
	gol -> worlds[NEXT] = gol -> worlds[CURRENT];
	gol -> worlds[CURRENT] = aux;
}

static bool rule(struct gol *gol, int x, int y, int rows, int columns)
{
	switch (count_neighbors(gol, x, y, rows, columns)){
	case 2: return gol -> worlds[CURRENT][x][y];
	case 3: return 1;
	default: return 0;
	}
}

static int count_neighbors(const struct gol *gol, int x, int y, int rows, int columns)
{
	// Devuelve el número de vecinos
	int neighbors = -gol -> worlds[CURRENT][x][y];
	
	for (int i = x-1; i <= x+1; i++){
		for (int j = y-1; j<= y+1; j++){
			neighbors += get_cell(gol, i, j, rows, columns);
		}
	}
	
	return neighbors;
}

static bool get_cell(const struct gol *gol, int x, int y, int rows, int columns)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	if ((x >= 0) && (x < rows) && (y >= 0) && (y < columns)) {
		return gol -> worlds[CURRENT][x][y];
	} else {
		return 0;	
	}
}
