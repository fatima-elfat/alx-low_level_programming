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
 * _strcmp - compare two string
 * @s1: first string
 * @s2: second string
 * Return: 0 equal negative value when s1 smaller the s2 and positive when bigger
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0, b = 0, l1, l2;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 < l2)
		l1 = l2;
	for (i = 0; i < l1; i++)
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			break;
		}

	return (a-b);
}
