#ifndef _GOL_H_
#define _GOL_H_

#define ROWS 15
#define COLUMNS 15

void gol_init(bool world[ROWS][COLUMNS][2], int);
void gol_print(bool world[ROWS][COLUMNS][2], int);
void gol_step(bool world[ROWS][COLUMNS][2], int);
int gol_count_neighbors(bool world[ROWS][COLUMNS][2], int, int, int);
bool gol_get_cell(bool world[ROWS][COLUMNS][2], int, int, int);

#endif
