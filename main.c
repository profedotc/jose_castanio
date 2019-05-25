#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

void gol_init(bool world[ROWS][COLUMNS]);
void gol_print(bool world[ROWS][COLUMNS]);
void gol_step(bool world[ROWS][COLUMNS], bool world_copy[ROWS][COLUMNS]);
int gol_count_neighbors(bool world[ROWS][COLUMNS], int x, int y);
bool gol_get_cell(bool world[ROWS][COLUMNS], int x, int y);
void gol_copy(bool world[ROWS][COLUMNS], bool world_copy[ROWS][COLUMNS]);

int main()
{
	int i = 0;
	// TODO: Declara dos mundos
	bool world[ROWS][COLUMNS];
	bool world_copy[ROWS][COLUMNS];
	// TODO: inicializa el mundo
	gol_init(world);
	
	do {
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(world);
		// TODO: Itera
		gol_step(world, world_copy);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void gol_init(bool world[ROWS][COLUMNS])
{
	// TODO: Poner el mundo a false
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			world[i][j] = 0;
		}
	}

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	char glider[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0},
	};
	
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			world[i][j] = glider[i][j];
		}
	};
}

void gol_print(bool world[ROWS][COLUMNS])
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
	for (int i = 1; i < ROWS - 1; i++){
		for (int j = 1; j < COLUMNS - 1; j++){
			printf("%c ", world[i][j]? '#' : '.');
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(bool world[ROWS][COLUMNS], bool world_copy[ROWS][COLUMNS])
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
	for (int i = 1; i < ROWS - 1; i++){
		for (int j = 1; j < COLUMNS - 1; j++){
			int neighbors = gol_count_neighbors(world, i, j);
			if (world[i][j]) {
				world_copy[i][j] = (neighbors == 3) || 
						   (neighbors == 2);
			} else {
				world_copy[i][j] = (neighbors == 3);
			}
		}
	}
	
	gol_copy(world, world_copy);
}

int gol_count_neighbors(bool world[ROWS][COLUMNS], int x, int y)
{
	// Devuelve el número de vecinos
	int neighbors = 0;
	neighbors += gol_get_cell(world, x - 1, y - 1);
	neighbors += gol_get_cell(world, x - 1, y + 0);
	neighbors += gol_get_cell(world, x - 1, y + 1);
				
	neighbors += gol_get_cell(world, x + 0, y - 1);
	neighbors += gol_get_cell(world, x + 0, y + 1);
				
	neighbors += gol_get_cell(world, x + 1, y - 1);
	neighbors += gol_get_cell(world, x + 1, y + 0);
	neighbors += gol_get_cell(world, x + 1, y + 1);
	
	return neighbors;
}

bool gol_get_cell(bool world[ROWS][COLUMNS], int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
	if ((x > (ROWS - 1)) || (y > (COLUMNS - 1))) {
		return 0;
	} else {
		return world[x][y];
	}
}

void gol_copy(bool world[ROWS][COLUMNS], bool world_copy[ROWS][COLUMNS])
{
	// TODO: copia el mundo segundo mundo sobre el primero
	for (int i = 1; i < ROWS - 1; i++) {
		for (int j = 1; j < COLUMNS - 1; j++) {
			world[i][j] = world_copy[i][j];
		}
	}
}
