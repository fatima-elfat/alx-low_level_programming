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
 * puts2 - prints every second character of a string
 * @str: string to print
 */

void puts2(char *str)
{
	int i;
	int j = _strlen(str);

	for (i = 0; str[i] != '\0' && i < j; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}
