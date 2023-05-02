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
	int i = 0;
	int l = (_strlen(s) - 1);
	char t;

	for (i = 0; i <= l; i++)
	{
		t = s[i];
		s[i] = s[l - i];
		s[l - i] = t;
		i++;
	}
}
