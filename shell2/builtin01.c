#include "shell.h"
/**
 * _biexit - exits the shell with a status.
 * @ar: the struct of args of shell.
 *  Return: exit status.
 */
int _biexit(l_ar *ar)
{
	int r;

	if (ar->argv[1])
	{
		r = _atoie(ar->argv[1]);
		if (r != -1)
		{
			ar->nerr = _atoie(ar->argv[1]);
			return (-2);
		}
		ar->st = 2;
		_printe(ar, "Illegal number: ");
		_putse(ar->argv[1]);
		_putechar('\n');
		return (1);
	}
	ar->nerr = -1;
	return (-2);
}
/**
 * _bienv - prints the current env.
 * @ar: the struct of args of shell.
 * Return: 0.
 */
int _bienv(l_ar *ar)
{
	_printl(ar->env);
	return (0);
}
/**
 * _bisetenv - initializes or modifies an env variable.
 * @ar: the struct of args of shell.
 *  Return: 0.
 */
int _bisetenv(l_ar *ar)
{
	if (ar->argc != 3)
	{
		_putse("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(ar, ar->argv[1], ar->argv[2]))
		return (0);
	return (1);
}
/**
 * _biunsetenv - removes an env variable.
 * @ar: the struct of args of shell.
 *  Return: 0.
 */
int _biunsetenv(l_ar *ar)
{
	int i;

	if (ar->argc == 1)
	{
		_putse("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= ar->argc; i++)
		_unsetenv(ar, ar->argv[i]);

	return (0);
}
