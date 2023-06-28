#include "shell.h"

/**
 * _getl - returns an array of strings.
 * @head: the head of the linked list.
 * Return: ...
 */
char **_getl(l_s *head)
{
	size_t i, j;
	char *s, **t;
	l_s *l = head;

	i = _getlenl(head);
	if (!head || !i)
		return (NULL);
	t = malloc(sizeof(char *) * (i + 1));
	if (!t)
		return (NULL);
	for (i = 0; l; l = l->next, i++)
	{
		s = malloc(_strlen(l->s) + 1);
		if (!s)
		{
			for (j = 0; j < i; j++)
				free(t[j]);
			free(t);
			return (NULL);
		}

		s = _strcpy(s, l->s);
		t[i] = s;
	}
	t[i] = NULL;
	return (t);
}
/**
 * _vrplce - replaces variables.
 * @ar: the struct of argument of shel of type struct list_args
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _vrplce(l_ar *ar)
{
	int i = 0;
	l_s *l;

	for (i = 0; ar->argv[i]; i++)
	{
		if (ar->argv[i][0] != '$' || !ar->argv[i][1])
			continue;

		if (!_strcmp(ar->argv[i], "$?"))
		{
			_strrplce(&(ar->argv[i]), _strdup(_itoa(ar->st, 10, 0)));
			continue;
		}
		if (!_strcmp(ar->argv[i], "$$"))
		{
			_strrplce(&(ar->argv[i]), _strdup(_itoa(getpid(), 10, 0)));
			continue;
		}
		l = get_node_with(ar->env, &ar->argv[i][1], '=');
		if (l)
		{
			_strrplce(&(ar->argv[i]), _strdup(_strchr(l->s, '=') + 1));
			continue;
		}
		_strrplce(&ar->argv[i], _strdup(""));

	}
	return (0);
}
/**
 * _cisch - returns if exists delimiter or not.
 * @ar: the struct list_ar of arguments of shell.
 * @s: the buffer.
 * @n: the current posix in buffer (adress).
 * Return: ...
 */
int _cisch(l_ar *ar, char *s, size_t *n)
{
	size_t r;

	r = *n;
	if (s[r] == ';')
	{
		ar->tcmd = CHN_C;
		s[r] = 0;
	}
	else if (s[r] == '|' && s[r + 1] == '|')
	{
		ar->tcmd = OR_C;
		s[r] = 0;
		r++;
	}
	else if (s[r] == '&' && s[r + 1] == '&')
	{
		ar->tcmd = AND_C;
		s[r] = 0;
		r++;
	}
	else
		return (0);
	*n = r;
	return (1);
}

/**
 * _cch - taking the last status to see if to continue.
 * @ar: the struct of args if shell.
 * @s: the sfer.
 * @n: the current posix in sfer(adress).
 * @i: the start posix in budder.
 * @len: the length ofsfer.
 */
void _cch(l_ar *l, char *s, size_t *n, size_t i, size_t len)
{
	size_t r;

	r = *n;
	if (ar->tcmd == OR_C)
	{
		if (!ar->st)
		{
			s[i] = 0;
			r = len;
		}
	}
	if (ar->tcmd == AND_C)
	{
		if (ar->st)
		{
			s[i] = 0;
			r = len;
		}
	}
	*n = r;
}
