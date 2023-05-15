#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * _strlen - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen(s));
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which con-
 * tains a copy of the string given as a parameter.
 * @str: input string.
 * Return: pointer to duplicated string.
 */
char *_strdup(char *str)
{
	char *p;
	int i, l;

	if (str == NULL)
		return (NULL);
	l = _strlen(str);
	p = malloc(l * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
		p[i] = str[i];
	p[i] = '\0';
	return (p);
}
