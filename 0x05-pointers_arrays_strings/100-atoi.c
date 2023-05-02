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
 * _atoi - convert string to int
 * @s: string to convert
 * Return: integer
 */

int _atoi(char *s)
{
	int l, m, n;
	char b;

	l = _strlen(s);
	n = 1;

	for (m = 0; m < l; m++)
	{
		if (s[m] == '-')
			n *= -1;
		else if ((s[m] <= '9') || (s[m] >= '0'))
		{
			b += s[m];
		}
		else if (b != 0)
			break;
	}
	if ( b == 0)
		n = 0;
	else
	{
		n *= (int) b;
	}
}

