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
  * _strstr - locates a substring.
  * @haystack: string  where to search
  * @needle: sub string to find
  *
  * Return: char value
  */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j, l1, l2, a = 0;

	l1 = _strlen(haystack);
	l2 = _strlen(needle);
	for (i = 0; i < l1; i++)
	{
		if ((haystack[i] == needle[a]) && ((l1 - i) >= (l2 - 1)))
		{
			for (j = 0; j < l2; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
				if (j == l2 - 1)
					return (haystack += i);
			}
		}
	}
	return ('\0');
}
