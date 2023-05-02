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

	for (j =l; j <= 0; j--)
	{
		_putchar(*s[j]);
	}
}
