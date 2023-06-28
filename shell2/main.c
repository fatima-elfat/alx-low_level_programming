#include "shell.h"

/**
* prompt - prompts shell.
* @ar: the struct list_ar.
* @argv: ...
* Return: 0 on success.
*/
int prompt(l_ar *ar, char **argv)
{
	int r = 0;
	ssize_t n = 0;

	while (r != -2 && n != -1)
	{
		_clarg(ar);
		if (_i_mode(ar))
			_puts("$ ");
		_eputchar(BUFFER_FLSH);
		n = _getline(ar);
		if (n != -1)
		{
			_setarg(ar, argv);
			r = _builtin(ar);
			if (r == -1)
				_inpath(ar);
		}
		else if (_i_mode(ar) != 0)
			_putchar('\n');
		_freearg(ar, 0);
	}
	_whist(ar);
	_freearg(ar, 1);
	if (!_i_mode(ar) && ar->st)
		exit(ar->st);
	if (r == -2)
	{
		if (ar->nerr != -1)
			exit(ar->nerr);
		exit(ar->st);
	}
	return (r);
}

/**
 * _builtin - searches if command is builtin.
 * @ar: the stuct of args list_ar.
 *
 * Return: 0 on success other -1, 1, 2.
 */
int _builtin(l_ar *ar)
{
	int r = -1, i;
	list_b bi[] = {
		{"exit", _biexit},
		{"env", _bienv},
		{"setenv", _bisetenv},
		{"unsetenv", _biunsetenv},
		{"cd", _bicd},
		{"help", _bihelp},
		{"history", _bihist},
		{"alias", _bialias},
		{NULL, NULL}
	};

	for (i = 0; bi[i].s; i++)
		if (_strcmp(ar->argv[0], bi[i].s) == 0)
		{
			ar->iline++;
			r = bi[i].f(ar);
			break;
		}
	return (r);
}
/**
 * _i_mode - is in intreractive mode.
 * @ar: the stuct with args of shell.
 * Return: 1 for yes.
 */
int _i_mode(l_ar *ar)
{
	int r;

	r = (ar->fd <= 2) && (isatty(STDIN_FILENO));
	return (r);
}

/**
 * _handlesig - handles the signal ctrl-c.
 * @n: the number of detected signal.
 */
void _handlesig(__attribute__((unused))int n)
{
	_puts("\n$ ");
	_putchar(BUFFER_FLSH);
}
/**
* main - the main entry function.
* @argc: arg count
* @argv: arg vector
* Return: 0 on success.
*/
int main(int argc, char **argv)
{
	int fd = 2;
	l_ar ar[] = { ININIT };

	asm ("mov %1, %0\n\tadd $3, %0": "=r" (fd): "r" (fd));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(arvv[1]);
				_eputchar('\n');
				_eputchar(BUFFER_FLSH);
				exit(E_VAL);
			}
			if (errno == EACCES)
				exit((E_VAL - 1));
			return (EXIT_FAILURE);
		}
		ar->fd = fd;
	}
	_envdup(ar);
	_rhist(ar);
	prompt(ar, argv);
	return (EXIT_SUCCESS);
}