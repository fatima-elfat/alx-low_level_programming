#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
* array_range - creates an array of integers.
* @min: the minimum value.
* @max: the maximum value.
* Return: pointer to the newly created array.
*/
int *array_range(int min, int max)
{
	int *p;
	int i, a;

	if (min > max)
		return (NULL);
	a = (max - min) + 1;
	p = malloc(sizeof(int) * a);
	if (p == NULL)
		return (NULL);
	for (i = 0; min < a; i++)
	{
		p[i] = min;
		min++;
	}
	return (p);
}
