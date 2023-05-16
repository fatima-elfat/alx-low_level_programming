#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of 2d array.
 * @height: height of 2d array.
 * Return: pointer to 2 dimensional array.
 */
int **alloc_grid(int width, int height)
{
	int i, j, **p;

	if (width <= 0 || height <= 0)
		return (NULL);
	p = malloc(sizeof(int) * height);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		p[i] = malloc(sizeof(int) * width);
		if (p[i] == NULL)
		{
			while (i >= 0)
			{
				free(p[i]);
			}
			free(p);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			p[i][j] = 0;

	return (p);

}
