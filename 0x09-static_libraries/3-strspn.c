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
 * _strspn - gets the length of a prefix substring.
 * @s: character to print
 * @accept: character
 * Return: length of prefix
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, l1, l2, r = 0;

	l1 = _strlen(s);
	l2 = _strlen(accept);
	for (i = 0; i < l1; i++)
	{
		for (j = 0; j < l2; j++)
		{
			if (s[i] == accept[j])
			{
				r++;
				break;
			}
			if (j == l2 - 1)
				return (r);
		}
	}
	return (r);
}
