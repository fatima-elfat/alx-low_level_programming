#include "main.h"
#include "6-abs.c"
#include <string.h>
/**
 * print_last_digit - last digit of input number
 * @i: number
 * Return: the last digit
 */
int print_last_digit(int i)
{
	int c;

	c = i % 10;
	c = _abs(c);
	_putchar('0' + c);
	return (c);
}
