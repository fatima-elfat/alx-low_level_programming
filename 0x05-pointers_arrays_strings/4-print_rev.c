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
	int i, j;
	int l = (_strlen(s) - 1);
	char t;
	char ss = s;

	for (i = 0; i <= l; i++)
	{
		t = s[i];
		s[i] = ss[l - i];
		ss[l - i] = t;
		i++;
	}
	for (j =0; j <= l; j++)
	{
		_putchar(ss[j]);
	}
}
