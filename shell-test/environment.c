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
	char *val = NULL;
	int i = 0, j, k, l = 0;

	while (e != NULL)
	{
		while (s[i] == (e->s1)[i])
			i++;
		if (s[i] == '\0' && (e->s1)[i] == '=')
			break;
		e = e->next;
		/*
		tk = _strtok(e->s1, '=');
		if (_strcmp(tk[0], s) == 0 && tk[1] != NULL)
		{
			val = _strcpy(val, tk[1]);
			return(val);
		}
		*/
	}
	i = 0;
	while ((e->s1)[i] != '=')
		i++;
	i++;
	j = i;
	while ((e->s1)[i] != '\0')
		i++;
	val = malloc(sizeof(char) * (i - j + 2));
	if (val == NULL)
		return NULL;
	for(k = j; k < i + 1; k++)
	{
		val[l] = (e->s1)[k];
		l++;
	}
	return (val);
}
