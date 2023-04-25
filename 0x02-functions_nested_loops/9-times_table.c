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
			int o;

			o = i * j;
			if (j == 0)
				_putchar('0' + o);
			else if (o < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + o);
			}
			else
			{
				int a, b;

				a = o % 10;
				b = o - a;
				b = b / 10;
				_putchar(' ');
				_putchar('0' + b);
				_putchar('0' + a);
			}
			if (j != 9)
				_putchar(',');
		}
		_putchar('\n');
	}
}
