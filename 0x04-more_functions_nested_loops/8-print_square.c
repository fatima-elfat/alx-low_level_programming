#include "main.h"

/**
 * print_square - print a square
 * @size: size of square
 */

void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 1; i < size + 1; i++)
		{
			for (j = 1; j < size + 1; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
