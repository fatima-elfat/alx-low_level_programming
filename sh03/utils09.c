#include "shell.h"

/**
 * _indlm - checks if delimiter.
 * @c: the input char.
 * @s: the delimeter.
 * Return: for true 1.
 */
int _indlm(char c, char *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}
/**
 * duppath - duplicates characters of path.
 * @s: the value of path.
 * @a: the starting point.
 * @b: the ending point.
 * Return: ...
 */
char *duppath(char *s, int a, int b)
{
	int i = 0, j = 0;
	static char buffer[BUFFER_SIZE_R];

	for (j = 0, i = a; i < b; i++)
		if (s[i] != ':')
			buffer[j++] = s[i];
	buffer[j] = 0;
	return (buffer);
}
/**
 * _getinpath - finds the command in
 * path and gets full path.
 * @ar: the structs of args of shell.
 * @p: the value of path.
 * @s: the value of command.
 * Return: ...
 */
char *_getinpath(l_ar *ar, char *p, char *s)
{
	int i = 0, pos = 0;
	char *path;

	if (!p)
		return (NULL);
	if ((_strlen(s) > 2) && _strbg(s, "./"))
	{
		if (_isexsec(ar, s))
			return (s);
	}
	while (1)
	{
		if (!p[i] || p[i] == ':')
		{
			path = duppath(p, pos, i);
			if (!*path)
				_strcat(path, s);
			else
			{
				_strcat(path, "/");
				_strcat(path, s);
			}
			if (_isexsec(ar, path))
				return (path);
			if (!p[i])
				break;
			pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * _setarg - make the initialization of args shell.
 * @ar: the structs of args of shell (adress).
 * @argv: list of argument in main.
 */
void _setarg(l_ar *ar, char **argv)
{
	int i = 0;

	ar->fname = argv[0];
	if (ar->arg)
	{
		ar->argv = _strtows(ar->arg, " \t");
		if (!ar->argv)
		{
			ar->argv = malloc(sizeof(char *) * 2);
			if (ar->argv == NULL)
				return;
			if (ar->argv)
			{
				ar->argv[0] = _strdup(ar->arg);
				ar->argv[1] = NULL;
			}
		}
		for (i = 0; ar->argv && ar->argv[i]; i++)
			;
		ar->argc = i;
		_vrplce(ar);
		_arplce(ar);
	}
}
/**
 * _seta - sets aliases.
 * @ar: parameter struct
 * @s: the string alias
 * Return: ...
 */
int _seta(l_ar *ar, char *s)
{
	char *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (_unseta(ar, s));

	_unseta(ar, s);
	return (add_node_end(&(ar->alias), s, 0) == NULL);
}
