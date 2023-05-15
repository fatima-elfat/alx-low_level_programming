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
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: pointer to the concatenated result.
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	char a = '\0';
	int i, l1, l2;

	if (s1 == NULL)
		s1 = &a;
	if (s2 == NULL)
		s2 = &a;
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	p = malloc((l1 + l2) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	if (l1 == 0 && l2 == 0)
		*p = '\0';
	else
	{
		for (i = 0; i < l1; i++)
			p[i] = s1[i];
		for (i = l1; i < l1 + l2; i++)
			p[i] = s2[i - l1];
		p[i] = '\0';
	}
	return (p);

}
