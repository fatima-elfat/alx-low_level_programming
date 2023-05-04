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
 * cap_string - capitalize string
 * @s: input string
 * Return: capitalized string
 */
char *cap_string(char *s)
{
	int i = 0, l, j;
	char a[13] = {'\t', '\n', ',', ';', '.', '!', '?', '"', ' ', '(', ')', '{'
		, '}'};

	l = _strlen(s);

	if ((s[i] <= 122) && (s[i] >= 97))
		s[i] -= 32;
	for (i = 1; i < l ; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (s[i - 1] == a[j])
			{
				if ((s[i] <= 122) && (s[i] >= 97))
					s[i] -= 32;
			}
		}
	}
	return (s);

}
