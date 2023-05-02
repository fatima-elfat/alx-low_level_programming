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
	char a,b;

	l = _strlen(s);
	n = 1;

	for (m = 0; m < l; m++)
	{
		a = *s;
		if (a == "-")
			n *= -1;
		else if ((a <= "9") || (a >= "0"))
		{
			b += a;
		}
		else if (b != 0)
			break;
		s++;
	}
	if ( b == 0)
		n = 0;
	else
	{
		n *= (int) b;
	}
}

