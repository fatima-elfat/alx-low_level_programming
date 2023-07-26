#include "shell.h"

/**
 * _strtok - splits a string into words
 * while ignoring the reapeting delimiters.
 * @s: the string.
 * @sd: the string delimeter.
 * Return: a pointer , or NULL if it fails.
 */

char **_strtok(char *s, char *sd)
{
	char **r;
	int a, b, c, d, e;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (sd == 0)
		sd = " ";
	e = getLenTok(s, sd);
	if (e == 0)
		return (NULL);
	r = malloc(sizeof(char *) * (e + 1));
	if (r == NULL)
		return (NULL);
	for (a = 0, b = 0; b < e; b++)
	{
		c = 0;
		while (inDlm(s[a], sd))
			a++;
		while (!inDlm(s[a + c], sd) && s[a + c])
			c++;
		r[b] = malloc(sizeof(char) * (c + 1));
		if (r[b] == NULL)
		{
			for (c = 0; c < b; c++)
				free(r[c]);
			free(r);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			r[b][d] = s[a++];
		r[b][d] = 0;
	}
	r[b] = NULL;
	return (r);
}

/**
 * _freetok - ...
 * @tk: ...
 */
void _freetok(char **tk)
{
	int i = 0;

	while (tk[i] != NULL)
	{
		free(tk[i]);
		i++;
	}
	free(tk);
}
/**
 * getLenTok - ...
 * @s: the string.
 * @sd: the string delimeter.
 * Return: length.
 */
int getLenTok(char *s, char *sd)
{
	int a, b, c, l = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		b = inDlm(s[a], sd);
		c = inDlm(s[a + 1], sd);
		if (!b && (!s[a + 1] || !c))
			l++;
	}
	return (l);
}
/**
 * inDlm - checks if delimiter.
 * @c: the input char.
 * @ds: the delimeter string.
 * Return: 0 on success.
 */
int inDlm(char c, char *ds)
{
	while (*ds)
		if (*ds++ == c)
			return (0);
	return (1);
}