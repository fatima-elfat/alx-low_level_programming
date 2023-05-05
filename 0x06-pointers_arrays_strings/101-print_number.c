#include "main.h"
/**
 * print_number - print an int
 * @n: int to be printed
 */

void print_number(int n)
{
	int j, k, l, m;
	double o = 0;

	if (n == 0)
		_putchar(48);
	else
	{
		if (n < 0)
		{
			_putchar(45);
			n *= -1;
		}
		while (n >= o)
			o *= 10;
		j = o / 10;
		m = n;
		while (j != 0)
		{
			if (n > j)
			{
				k = m % j;
				l = (m - k) / j;
				m = k;
				_putchar(l + '0');
			}
			if (j != 1)
				j /= 10;
			else
				j = 0;
		}
	}
}
