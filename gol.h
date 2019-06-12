#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define ROWS 15
#define COLUMNS 15

struct gol{
	bool world[ROWS][COLUMNS][2];
	int current_world;
};

void gol_init(struct gol *gol);
void gol_print(struct gol *gol);
void gol_step(struct gol *gol);
int gol_count_neighbors(struct gol *gol, int, int);
bool gol_get_cell(struct gol *gol, int, int);

#endif
