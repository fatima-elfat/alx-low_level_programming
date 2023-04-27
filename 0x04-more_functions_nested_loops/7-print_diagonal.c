#include "main.h"

/**
 * print_diagonal - print diagonal using  "\"
 * @n: number of chars to draw
 */

void print_diagonal(int n)
{
	int i, j;

	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < i - 1; j++)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
	_putchar('\n');
}
