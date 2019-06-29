#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

#define ITER 1000
#define ROWS 15
#define COLUMNS 15

int main ()
{
    struct gol gol;
    
    gol_alloc(&gol, ROWS, COLUMNS);
    gol_init(&gol, ROWS, COLUMNS);
    
    for (int i = 0; i < ITER; i++) {
            gol_step(&gol, ROWS, COLUMNS);
    }
    
    gol_free(&gol, COLUMNS);
        
    return EXIT_SUCCESS;
}
