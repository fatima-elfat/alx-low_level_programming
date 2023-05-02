#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}
/**
 * print_rev - reverses a string
 * @s: string to reverse
 */

void print_rev(char *s)
{
	int j;
	int l = (_strlen(s) - 1);
	char m;

	for (j =0; j <= l; j++)
	{
		*s = m[l - j];
		s--;
	}
	for (j =0; j <= l; j++)
	{
		_putchar(m[j]);
	}
	_putchar('\n');
}
