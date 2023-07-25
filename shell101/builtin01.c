#include "shell.h"
/**
 * biExit - exits the shell with a status.
 * @ar: the struct of args of shell.
 *  Return: exit status.
 */
int biExit(l_ar *ar)
{
	int r;

	if (ar->argv[1])
	{
		r = _atoi(ar->argv[1]);
		if (r != -1)
		{
			ar->nerr = _atoi(ar->argv[1]);
			return (-2);
		}
		ar->st = 2;
		_puts(ar->fname);
		_puts(": ");
		_printd(STDERR_FILENO, ar->iline);
		_puts(": ");
		_puts(ar->argv[0]);
		_puts(": Illegal number: ");
		_puts(ar->argv[1]);
		_putchar('\n');
		return (1);
	}
	ar->nerr = -1;
	return (-2);
}