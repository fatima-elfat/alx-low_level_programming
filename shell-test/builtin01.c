#include "shell.h"


int _bi_exit(char **tk)
{
	int i = 0;

	if (tk[1] == NULL)
		{
			_freetok(tk);
			exit(0);
		}
	else
		i = _atoi(tk[1]);
	if (i < 0)
	{
		_puts("exit: Illegal number: ");
		_puts(tk[1]);
		_putchar('\n');
		return (-1);
	}
	_freetok(tk);
	exit(i);
}
