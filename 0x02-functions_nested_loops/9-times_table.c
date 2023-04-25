#include "main.h"
/**
 * times_table - time table of nine
 * Return: void
 */
void times_table(void)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			_putchar('0' + i*j);
			_putchar(', ');
		}
		_putchar('\n');
	}
}
