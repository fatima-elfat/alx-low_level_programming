#include "main.h"
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
