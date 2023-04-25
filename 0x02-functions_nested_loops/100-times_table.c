#include "main.h"
/**
 * print_times_table - time table of n
 * @n: number
 * Return: void
 */
void print_times_table(int n)
{
	int i, j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int o;

			o = i * j;
			if (j == 0)
				_putchar('0' + o);
			else if (o < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + o);
			}
			else if (o < 100)
			{
				int a, b;

				a = o % 10;
				b = o - a;
				b = b / 10;
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + b);
				_putchar('0' + a);
			}
			else
			{
				int a, b, c;

				a = o % 100;
				b = o - a;
				c = b / 100;
				_putchar(' ');
				_putchar('0' + c);
				a = b % 10;
				c = b - a;
				c = c / 10;
				_putchar('0' + c);
				_putchar('0' + a);
			}
			if (j != n )
				_putchar(',');
		}
		_putchar('\n');
	}
}
