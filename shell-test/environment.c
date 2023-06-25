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
char *_getenvval(char *s)
{
	int i = 0;
	char *val = NULL;


	while (e != NULL)
	{
		if (_strncmp(e->s1, s) == 0)
		{
			val = _strcpy(val, e->s1);
			while (*val != '=')
			{
				val++;
			}
			val++;
			return(val);
		}
		else
		{
			e = e->next;
		}
	}
	return (NULL);	
}
