#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define ROWS 15
#define COLUMNS 15

struct gol{
	bool world[ROWS][COLUMNS][2];
	unsigned int current_world;
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);

#endif
