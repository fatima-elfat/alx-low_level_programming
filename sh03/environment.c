#include "shell.h"
/**
 * _getenv - gets the env value.
 * @ar: the struct of args of shell.
 * @s: the siable in env.
 * Return: ...
 */
char *_getenv(l_ar *ar, const char *s)
{
	char *p;
	l_s *l;

	l = ar->env;
	while (l)
	{
		p = _strbg(l->s, s);
		if (p && *p)
			return (p);
		l = l->next;
	}
	return (NULL);
}
/**
 * get_envr - returns copy of the environ.
 * @ar: the struct of args of shell.
 * Return: 0.
 */
char **get_envr(l_ar *ar)
{
	if (!ar->envr || ar->dif_env)
	{
		ar->envr = _getl(ar->env);
		ar->dif_env = 0;
	}
	return (ar->envr);
}
/**
 * _setenv - initializes or modifies an env siable.
 * @ar: the struct of args of shell.
 * @s1: the string of property.
 * @s2: the string of value.
 *  Return: ...
 */
int _setenv(l_ar *ar, char *s1, char *s2)
{
	char *p, *buffer = NULL;
	l_s *l;

	if (!s1 || !s2)
		return (0);
	buffer = malloc((_strlen(s1) + _strlen(s2) + 2));
	if (buffer == NULL)
		return (1);
	_strcpy(buffer, s1);
	_strcat(buffer, "=");
	_strcat(buffer, s2);
	l = ar->env;
	while (l)
	{
		p = _strbg(l->s, s1);
		if (p && *p == '=')
		{
			free(l->s);
			l->s = buffer;
			ar->dif_env = 1;
			return (0);
		}
		l = l->next;
	}
	add_node_end(&(ar->env), buffer, 0);
	free(buffer);
	ar->dif_env = 1;
	return (0);
}
/**
 * _unsetenv - removes a variable of environment.
 * @ar: the struct of args of shell.
 * @s: the string of property.
 *  Return: ...
 */
int _unsetenv(l_ar *ar, char *s)
{
	char *p;
	l_s *l;
	size_t i = 0;

	l = ar->env;
	if (!l || !s)
		return (0);

	while (l != NULL)
	{
		p = _strbg(l->s, s);
		if (*p == '=' && p)
		{
			ar->dif_env = delete_node_at_index(&(ar->env), i);
			l = ar->env;
			i = 0;
			continue;
		}
		l = l->next;
		i++;
	}
	return (ar->dif_env);
}
/**
 * _envdup - dup the linked list environmrnt.
 * @ar: the struct of args of shell.
 * Return: 0.
 */
int _envdup(l_ar *ar)
{
	size_t i;
	l_s *l = NULL;

	for (i = 0; environ[i]; i++)
		add_node_end(&l, environ[i], 0);
	ar->env = l;
	return (0);
}
