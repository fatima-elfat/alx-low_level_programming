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
 * leet - Write a function that encodes a string into 1337
 * @s: input string
 * Return: encoded char
 */
char *leet(char *s)
{
	int i, j, l;
	char r[10] = {'4', '3', '0', '7', '1', '4', '3', '0', '7', '1'};
	char lc[10] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};

	l = _strlen(s);
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (lc[j] == s[i])
				s[i] = r[j];
		}
	}
	return (s);
}
