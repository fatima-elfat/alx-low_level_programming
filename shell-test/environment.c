#include "shell.h"

l_u *_getenv(char **env)
{
	int i = 0;
	l_u *linked;
	char *s2;

	s2 = " ";
	while (env[i])
	{
		add_node(&linked, env[i], s2);
		i++;
	}
	return (linked);
}
char *_getenvval(char *s, l_u *e)
{
	char *val = NULL, **tk;


	while (e != NULL)
	{
		tk = _strtok(e->s1, '=');
		if (_strcmp(tk[0], s) == 0)
		{
			val = _strcpy(val, tk[1]);
			/*
			while (*val != '=')
			{
				val++;
			}
			val++;
			*/
			return(val);
		}
		else
		{
			e = e->next;
		}
	}
	return (NULL);	
}
