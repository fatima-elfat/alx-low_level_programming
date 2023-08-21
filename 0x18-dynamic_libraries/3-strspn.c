#include "main.h"

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
