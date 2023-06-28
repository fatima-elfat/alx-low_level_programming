#include "shell.h"


/**
 * **strtows - splits a string into words
 * while ignoring the reapeting delimiters.
 * @s: the string.
 * @a: the string delimeter.
 * Return: a pointer , or NULL if it fails.
 */

char **strtows(char *s, char *a)
{
	char **ps;
	int i, j, k, m, n = 0;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!a)
		a = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!_indlm(s[i], a))
		{
			if (_indlm(s[i + 1], a) || !s[i + 1])
				n++;
		}
	if (n == 0)
		return (NULL);
	ps = malloc(sizeof(char *) * (1 + n));
	if (ps == NULL)
		return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
		while (_indlm(s[i], a))
			i++;
		k = 0;
		while (!_indlm(s[i + k], a) && s[i + k])
			k++;
		ps[j] = malloc(sizeof(char) * (k + 1));
		if (ps[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(ps[k]);
			free(ps);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			ps[j][m] = s[i++];
		ps[j][m] = 0;
	}
	ps[j] = NULL;
	return (ps);
}

/**
 * _strbg - checks if string b starts with a.
 * @a: the string to search.
 * @b: the string to find.
 * Return: pointer to next char or NULL.
 */
char *_strbg(const char *a, const char *b)
{
	while (*b)
		if (*b++ != *a++)
			return (NULL);
	return ((char *)a);
}

/**
 * _strrplce - replaces the value of a string.
 * @s1: the old string pointer.
 * @s2: the new string.
 * Return: 1 success, else 0.
 */
int _strrplce(char **s1, char *s2)
{
	free(*s1);
	*s1 = s2;
	return (1);
}
