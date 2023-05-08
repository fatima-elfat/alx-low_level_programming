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
 * _strchr - locates a character in a string.
 * @s: string of input
 * @c: char to locate
 * Return:return a pointer to the frst occurence or NULL
 */
char *_strchr(char *s, char c)
{
	unsigned int i, l;

	l = _strlen(s);
	for (i = 0; i < l; i++)
	{
		if (s[i] == c)
		{
			s += i;
			return (s);
		}
	}
	return ('\0');

}
