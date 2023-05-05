#include "main.h"
/**
 * print_number - print an int
 * @n: int to be printed
 */

void print_number(int n)
{
	int a;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}
	a = n;
	if (n / 10 != 0)
		print_number(n / 10);
	_putchar((a % 10) + '0');

}
