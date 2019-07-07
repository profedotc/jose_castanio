#include "gol.h"

#include <stdio.h>
#include <stdlib.h>

enum state{ CURRENT, NEXT };

static void fix_coords(const struct gol *gol, int *x, int *y);
static void set_cell(struct gol *gol, enum state s, int x, int y, bool alive);
static bool get_cell(const struct gol *gol, enum state s, int x, int y);
static int count_neighbors(const struct gol *gol, int x, int y);
static bool rule(struct gol *gol, int x, int y);

bool gol_alloc(struct gol *gol, int rows, int columns)
{
	for (int i = CURRENT; i <= NEXT; i++){
		gol -> worlds[i] = (bool *)malloc(rows * columns * sizeof(bool));
		if (!gol -> worlds[i]) return false;  
  	}

	gol -> n_rows = rows;
	gol -> n_columns = columns;
  	
	return true;
}

void gol_free(struct gol *gol)
{
	for (int i = CURRENT; i <= NEXT; i++){
		free(gol -> worlds[i]);
	}
}

void gol_init(struct gol *gol)
{
	// TODO: Poner el mundo a false
	for (int i = 0; i < gol -> n_rows; i++){
		for (int j = 0; j < gol -> n_columns; j++){
			set_cell(gol, CURRENT, i, j, false);
		}
	}

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	set_cell(gol, CURRENT, 0, 0, false);
	set_cell(gol, CURRENT, 0, 1, true);
	set_cell(gol, CURRENT, 0, 2, false);
	
	set_cell(gol, CURRENT, 1, 0, false);
	set_cell(gol, CURRENT, 1, 1, false);
	set_cell(gol, CURRENT, 1, 2, true);
	
	set_cell(gol, CURRENT, 2, 0, true);
	set_cell(gol, CURRENT, 2, 1, true);
	set_cell(gol, CURRENT, 2, 2, true);
}

void gol_print(const struct gol *gol)
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
	for (int i = 0; i < gol -> n_rows; i++){
		for (int j = 0; j < gol -> n_columns; j++){
			printf("%c ", get_cell(gol, CURRENT, i, j)? 
					'#' : '.');
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct gol *gol)
{
	for (int i = 0; i < gol -> n_rows; i++){
		for (int j = 0; j < gol -> n_columns; j++){
			set_cell(gol, NEXT, i, j, rule(gol, i, j));
		}
	}
	
	bool *aux = gol -> worlds[NEXT];
	gol -> worlds[NEXT] = gol -> worlds[CURRENT];
	gol -> worlds[CURRENT] = aux;
}

static bool rule(struct gol *gol, int x, int y)
{
	switch (count_neighbors(gol, x, y)){
	case 2: return get_cell(gol, CURRENT, x, y);
	case 3: return 1;
	default: return 0;
	}
}

static int count_neighbors(const struct gol *gol, int x, int y)
{
	// Devuelve el número de vecinos
	int neighbors = -get_cell(gol, CURRENT, x, y);
	
	for (int i = x-1; i <= x+1; i++){
		for (int j = y-1; j<= y+1; j++){
			neighbors += get_cell(gol, CURRENT, i, j);
		}
	}
	
	return neighbors;
}

static bool get_cell(const struct gol *gol, enum state s, int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	fix_coords(gol, &x, &y);
	return gol -> worlds[s][x * gol -> n_columns + y];
}

static void set_cell(struct gol *gol, enum state s, int x, int y, bool alive){
	fix_coords(gol, &x, &y);
	gol -> worlds[s][x * gol -> n_columns + y] = alive;
}

static void fix_coords(const struct gol *gol, int *x, int*y)
{
	if (*x >= gol -> n_rows)
		*x = 0;
	else if (*x < 0)
		*x = gol -> n_rows - 1;

	if (*y >= gol -> n_columns)
		*y = 0;
	else if (*y < 0)
		*y = gol -> n_columns - 1;
} 
