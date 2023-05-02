#include "main.h"
/**
 * swap_int - swaps the value
 * @a: int to swap
 * @b: int to swap
 */

void swap_int(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}
