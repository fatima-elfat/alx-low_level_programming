#include "main.h"
/**
 * leet - Write ia function that encodes a string into 1337
 * @s: input string
 * Return: encoded char
 */
char *leet(char *s)
{
	int i, j;
	char r[10] = {'4', '3', '0', '7', '1', '4', '3', '0', '7', '1'};
	char lc[10] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};

	for (i = 0; i != '\0'; i++)
	{
		for (j = 0; j != '\0'; j++)
		{
			if (lc[j] == s[i])
				s[i] = r[j];
		}
	}
	return (s);
}
