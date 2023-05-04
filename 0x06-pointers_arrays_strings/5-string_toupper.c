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
 * string_toupper - all lowercase string to uppercase
 * @s: input string
 * Return: string after changes
 */
char *string_toupper(char *s)
{
	int i, l;

	l = _strlen(s);

	for (i = 0; i < l; i++)
	{
		if ((s[i] <= 122) && (s[i] >= 97))
			s[i] -= 32;
	}
	return (s);
}
