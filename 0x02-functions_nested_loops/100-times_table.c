#include "main.h"
/**
 * print_times_table - time table of n
 * @n: number
 * Return: void
 */
void print_times_table(int n)
{
	int i, j, o, a, b, c;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				o = i * j;
				if (j == 0)
					_putchar('0' + o);
				else
				{
					_putchar(' ');
					if (o < 10)
					{
						_putchar(' ');
						_putchar(' ');
						_putchar('0' + o);
					}
					else if (o < 100)
					{
						a = o % 10;
						b = (o - a) / 10;
						_putchar(' ');
						_putchar('0' + b);
						_putchar('0' + a);
					}
					else
					{
						a = o % 100;
						c = (o - a) / 100;
						_putchar('0' + c);
						b = a % 10;
						c = (a - b) / 10;
						_putchar('0' + c);
						_putchar('0' + b);
					} }
				if (j != n)
					_putchar(',');} _putchar('\n');} } }
