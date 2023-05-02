#include "main.h"

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
 * puts_half - function prints second half of a string
 * @str: input string
 */
void puts_half(char *str)
{
	int i, j;
	int l = _strlen(str);
	int n;

	if (l % 2 != 0) 
		n = (l - 1) / 2;
	else
		n = l / 2;
	for (i = 0; i < n ; i++)
	{
		str++;
	}
	for(i = n; i < l; i++)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
