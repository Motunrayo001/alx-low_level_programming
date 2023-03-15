#include "main.h"
#include <stdlib.h>

/**
 * free_grid- function that frees a 2 dimensional grid
 * previously created by your alloc_grid function.
 * Note that we will compile with your alloc_grid.c
 * Make sure it compiles.
 * @grid: the grid
 * @height: the height of the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
