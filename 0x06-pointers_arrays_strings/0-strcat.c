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
 * _strcat - concatenates two strings
 * @dest: input string t append to
 * @src: input string to be appended
 * Return: resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, l1, l2;

	l1 = _strlen(dest);
	l2 = _strlen(src);

	for (i = 0; i < l2 ; i++)
		dest[l1 + i] += src[i];
	dest[l1 + i] = '\0';
	return (dest);
}
