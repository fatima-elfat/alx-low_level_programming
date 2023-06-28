#include "shell.h"


/**
 * _bicd - changes the current dir.
 * @ar: the struct of args of shell.
 *  Return: ...
 */
int _mycd(l_ar *ar)
{
	int r;
	char *s, *dir, buffer[BUFFER_SIZE_R];

	s = getcwd(buffer, BUFFER_SIZE_R);
	if (s == NULL)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!ar->argv[1])
	{
		dir = _getenv(ar, "HOME=");
		if (dir)
			r = chdir(dir);
		else
			r = chdir((dir = _getenv(ar, "PWD=")) ? dir : "/");
	}
	else if (_strcmp(ar->argv[1], "-") == 0)
	{
		if (!_getenv(ar, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(ar, "OLDPWD=")), _putchar('\n');
		r = chdir((dir = _getenv(ar, "OLDPWD=")) ? dir : "/");
	}
	else
		r = chdir(ar->argv[1]);
	if (r != -1)
	{
		_setenv(ar, "OLDPWD", _getenv(ar, "PWD="));
		_setenv(ar, "PWD", getcwd(buffer, BUFFER_SIZE_W));
	}
	else
	{
		_printe(ar, "can't cd to ");
		_putse(ar->argv[1]);
		_putechar('\n');
	}
	return (0);
}

/**
 * _bihelp - asks for help.
 * @ar: the struct of args of shell.
 *  Return: ...
 */
int _bihelp(l_ar *ar)
{
	char **r;

	r = ar->argv;
	_puts("help call works.\n");
	if (0)
		_puts(*r);
	return (0);
}
/**
 * _bihist - shows the history.
 * @ar: the struct of args of shell.
 *  Return: 0.
 */
int _bihist(l_ar *ar)
{
	_printlall(ar->hist);
	return (0);
}
/**
 * _bialias - ...
 * @ar: ...
 *  Return: ...
 */
int _bialias(l_ar *ar)
{
	l_s *l = NULL;
	int i = 0;
	char *s = NULL;

	if (ar->argc == 1)
	{
		l = ar->alias;
		while (l)
		{
			_printa(l);
			l = l->next;
		}
		return (0);
	}
	for (i = 1; ar->argv[i]; i++)
	{
		s = _strchr(ar->argv[i], '=');
		if (!s)
			_printa(get_node_with(ar->alias, ar->argv[i], '='));
		else
			_seta(ar, ar->argv[i]);
	}
	return (0);
}
/**
 * _delcom - replaces the commentary delimiter '#'.
 * @s: the string to modify.
 */
void _delcom(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if ((i == 0 || s[i - 1] == ' ') && s[i] == '#')
		{
			s[i] = '\0';
			break;
		}
}
