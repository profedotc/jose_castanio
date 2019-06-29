#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define ROWS 15
#define COLUMNS 15

struct gol{
	bool **worlds[2];
};

void gol_init(struct gol *gol, int rows, int columns);
void gol_print(const struct gol *gol, int rows, int columns);
void gol_step(struct gol *gol, int rows, int columns);
void gol_alloc(struct gol *gol, int rows, int columns);
void gol_free(struct gol *gol, int columns);

#endif
