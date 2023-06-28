#include "shell.h"


/**
 * _clarg - clears args and
 * value of path to initilize stuct
 * @ar: the sturct of argument of the shell
 */
void _clarg(l_ar *ar)
{
	ar->path = NULL;
	ar->argc = 0;
	ar->arg = NULL;
	ar->argv = NULL;
}
/**
 * _arplce - replaces tha alias.
 * @ar: the struct list_arg of argument about the shell.
 * Return: ...
 */
int _arplce(l_ar *ar)
{
	int i;
	l_s *l;
	char *ptr;

	for (i = 0; i < A_VAL; i++)
	{
		l = get_node_with(ar->alias, ar->argv[0], '=');
		if (l == NULL)
			return (0);
		free(ar->argv[0]);
		ptr = _strchr(l->s, '=');
		if (ptr == NULL)
			return (0);
		ptr = _strdup(ptr + 1);
		if (ptr == NULL)
			return (0);
		ar->argv[0] = ptr;
	}
	return (1);
}
/**
 * _freearg - frees struct l_ar fields.
 * @ar: the struct list_arg of argument about the shell.
 * @n: the value of answer to free all fiels?
 */
void _freearg(l_ar *ar, int n)
{
	_strfree(ar->argv);
	ar->argv = NULL;
	ar->path = NULL;
	if (n)
	{
		if (ar->env)
			freel(&(ar->env));
		_strfree(ar->envr);
		ar->envr = NULL;
		if (!ar->bcmd)
			free(ar->arg);
		if (ar->hist)
			freel(&(ar->hist));
		if (ar->alias)
			freel(&(ar->alias));
		freep((void **)ar->bcmd);
		if (ar->fd > 2)
			close(ar->fd);
		_putchar(BUFFER_FLSH);
	}
}

/**
 **_memset - fills memory with a byte.
 *@s: the memory area (pointer).
 *@a: the byte to fill.
 *@n: the number of bytes.
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char a, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = a;
	return (s);
}
/**
 * _strr - reads the given buffer.
 * @ar: the struct of args of shell.
 * @s: the string buffer.
 * @i: the size in bytes.
 * Return: ...
 */
ssize_t _strr(l_ar *ar, char *s, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(ar->fd, s, BUFFER_SIZE_R);
	if (r >= 0)
		*i = r;
	return (r);
}
