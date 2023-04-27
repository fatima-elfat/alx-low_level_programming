#include "main.h"
/**
 * print_number - print an int
 * @n: int to be printed
 */

void print_number(int n)
{
	int j, k, l;

	if (n < 0)
	{
		_putchar(45);
		n *= -1;
	}

	j = 1000;

	while (j != 0)
	{
		if (n > j)
		{
			k = n % j;
			l = (n - k) / j;
			n = k;
			_putchar('0' + l);
		}
		if (j != 1)
			j /= 10;
		else
			j = 0;
	}
}
