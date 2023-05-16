#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * free_grid -  frees a 2d grid previously created by alloc_grid function.
 * @grid: 2 dimensional array.
 * @height: height of array.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid != NULL && height != 0)
	{
		for (i = height; i < 0; i--)
			free(grid[i]);
		free(grid);
	}
}
