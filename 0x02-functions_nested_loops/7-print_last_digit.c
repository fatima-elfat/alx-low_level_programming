#include "main.h"
#include <string.h>
/**
 * print_last_digit - last digit of input number
 * @i: number
 * Return: the last digit
 */
int print_last_digit(int i)
{
	int o;
	int c;

	char l[] = i;
	o = (int)strlen(l);
	c = l[o];
	_putchar((char)c);
	return (c);
}
