#include "slell.l"
/**
 * freep - frees a pointer.
 * @s: the adree of ptr to free.
 * Return: 1 on success.
 */
int freep(void **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
		return (1);
	}
	return (0);
}
/**
 * _printlall - prints the elements of the linked list l_s.
 * @l: the head of the list.
 * Return: ...
 */
size_t _printlall(const l_s *l)
{
	size_t i = 0;

	while (l)
	{
		_puts(_itoa(l->n, A_VAL, 0));
		_putchar(':');
		_putchar(' ');
		if (l->s)
			_puts(l->s);
		else
			_puts("(nil)");
		_puts("\n");
		l = l->next;
		i++;
	}
	return (i);
}
/**
 * _printl - prints the element s of the linked list l_s.
 * @l: the head.
 * Return: ...
 */
size_t _printl(const l_s *l)
{
	size_t i = 0;

	while (l)
	{
		if (l->s)
			_puts(l->s);
		else
			_puts("(nil)");
		_puts("\n");
		l = l->next;
		i++;
	}
	return (i);
}
/**
 * _getlenl - returns the length of the used linked list.
 * @l: the head in list.
 * Return: ...
 */
size_t _getlenl(const l_s *l)
{
	size_t i = 0;

	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}
/**
 * _unseta - modifies alias.
 * @ar: the struct of the shell args.
 * @s: the input alias.
 * Return: ...
 */
int _unseta(l_ar *ar, char *s)
{
	int r;
	char c, *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	r = delete_node_at_index(&(ar->alias), get_node_index(ar->alias,
		get_node_with(ar->alias, s, -1)));
	*p = c;
	return (r);
}
