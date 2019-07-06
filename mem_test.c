#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

#define ITER 1000

int main ()
{
    struct gol gol;
    
    gol_alloc(&gol, 15, 20);
    gol_init(&gol);
    
    for (int i = 0; i < ITER; i++) {
            gol_step(&gol);
    }
    
    gol_free(&gol);
        
    return EXIT_SUCCESS;
}
