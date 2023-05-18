#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * _strlen_recursion - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}
/**
 * string_nconcat - concatenates two strings.
 * @s1: the first string.
 * @s2: the second string.
 * @n: the number of byte to add from s2.
 * Return: pointer of concatenated strings.
 **/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int  i, l1, l2, l;

	if (s1 == NULL)
		s1 = '\0';
	if (s2 == NULL)
		s2 = '\0';
	l1 = _strlen_recursion(s1);
	l2 = _strlen_recursion(s2);
	if (n > l2)
		n = l2;
	l = l1 + n;
	p = malloc(l + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
	{
		if (i < l1)
			p[i] = s1[i];
		else
			p[i] = s2[i - l1];
	}
	return (p);
}
