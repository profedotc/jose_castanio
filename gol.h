#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

struct gol{
	bool *worlds[2];
	int n_rows;
	int n_columns;
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);
bool gol_alloc(struct gol *gol, int rows, int columns);
void gol_free(struct gol *gol);

#endif
