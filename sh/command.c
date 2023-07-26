#include "shell.h"
/**
 * isbuiltin - ...
 * @token: ...
 * @e: ...
 * Return: ...
 */
int isbuiltin(char **token, l_u *e)
{
	if (token == NULL)
		return (-1);
	if (token[0] == NULL)
		return (-1);
	if (!_strcmp(token[0], "exit"))
		_bi_exit(token);
	else if (!_strcmp(token[0], "env"))
		_bi_env(e);
	/**
	 * else if (!_strcmp(token[0], "setenv"))
	 * r = _bi_setenv(token[1], token[2]);
	 * else if (!_strcmp(token[0], "unsetenv"))
	 * r = _bi_unsetenv(token[1]);
	 * else if (_strcmp(token[0], "cd") == 0)
	 * r = _bi_cd(token);
	 * else if (!_strcmp(token[0], "alias"))
	 * r = _bi_alias(token);
	 */
	else
		return (0);
	return (1);
}
/**
 * isexecute - ...
 * @tk: ...
 * @e: ...
 * Return: ...
 */
int isexecute(char **tk, l_u *e)
{
	char *p = NULL;
	int st = 0, l = 0, i;
	pid_t child;

	p = isinpath(tk[0], e);
	while (*tk++)
	{
		i++;
	}
	for (i = 0; i < l; i++)
	{
		p = isinpath(tk[i], e);
		printf("command path %s\n", p);
		if (!access(p, X_OK))
			{
				printf("path exist\n");
				break;
			}
	}
	if (!access(p, X_OK))
	{
		child = fork();
		if (child == 0)
		{
			/*val = _lenv(e);*/
			if (execve(p, tk, NULL) == -1)
			{

				_puts("fork: failed: ");
				_puts(tk[0]);
				_putchar('\n');
				free(p);
				exit(0);
			}
		}
		else
		{
			wait(&st);
			free(p);
		}
	}
	else
	{
		_puts("fork: failed: ");
		_puts(tk[0]);
		_putchar('\n');
		free(p);
		return (-1);
	}
	return (0);
}
