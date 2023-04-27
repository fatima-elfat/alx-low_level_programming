#include "main.h"

/**
 * print_triangle - print traingle of #
 * @size: size of triangle
 */

void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
		_putchar('\n');

	for (i = 1; i < size + 1; i++)
	{
		for (j = 1; j < (size - i) + 1; j++)
			_putchar(' ');

		for (k = j; k < size + 1 ; k++)
			_putchar('#');

		_putchar('\n');
	}
}
