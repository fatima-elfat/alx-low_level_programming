#include "shell.h"

int isbuiltin(char **token)
{
	if (token[0] == NULL)
		return (-1);
	if (!_strcmp(token[0], "exit"))
		_bi_exit(token);
	/*
	else if (!_strcmp(token[0], "env"))
		r = _bi_env();
	else if (!_strcmp(token[0], "setenv"))
		r = _bi_setenv(token[1], token[2]);
	else if (!_strcmp(token[0], "unsetenv"))
		r = _bi_unsetenv(token[1]);
	else if (_strcmp(token[0], "cd") == 0)
		r = _bi_cd(token);
	else if (!_strcmp(token[0], "alias"))
		r = _bi_alias(token);
	*/
	else
		return (0);
	return (1);
}
int isexecute(char **tk, l_u *e)
{
	char *p;
	int st = 0;
	pid_t child;

	p = isinpath(tk[0], e);
	if (!access(p, X_OK))
	{
		child = fork();
		if ( child == 0)
		{
			if (execve(p, tk, NULL) == -1)
			{
				_puts("fork: failed: ");
				_puts(tk[0]);
				_freetok(tk);
				free(p);
				exit(0);
			}
		}
		else
		{
			wait(&st);
			free(p);
			_freetok(tk);
		}
	}
	else
	{
		_puts("command: failed: ");
		_puts(tk[0]);
		free(p);
		_freetok(tk);
		return (-1);
	}
	return (0);
}
