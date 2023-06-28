#include "shell.h"

/**
 * get_node_with - finds node which its s val
 * starts with the given string s.
 * @l: the pointer to head of l_s.
 * @s: tthe string to match.
 * @c: the next character to match.
 * Return: ...
 */
l_s *get_node_with(l_s *l, char *s, char c)
{
	char *str = NULL;

	while (l != NULL)
	{
		str = _strbg(l->s, s);
		if (str && ((c == -1) || (*str == c)))
			return (l);
		l = l->next;
	}
	return (NULL);
}
/**
 * add_node_end - adds a new node at the end
 * of a l_s list.
 * @head: the linked list.
 * @s: the value of the field in node.
 * @i: the index in hist.
 *
 * Return: size of list
 */
l_s *add_node_end(l_s **head, const char *s, int i)
{
	l_s *n1, *n2;

	if (head == NULL)
		return (NULL);
	n1 = malloc(sizeof(l_s));
	n2 = *head;
	if (n1 == NULL)
		return (NULL);
	_memset((void *)n1, 0, sizeof(l_s));
	n1->n = i;
	if (s)
	{
		n1->s = _strdup(s);
		if (!n1->s)
		{
			free(n1);
			return (NULL);
		}
	}
	if (n2)
	{
		while (n2->next)
			n2 = n2->next;
		n2->next = n1;
	}
	else
		*head = n1;
	return (n1);
}
/**
 * get_node_index - returns the index of the given node.
 * @l: the head of linked list.
 * @n: the node.
 * Return: index of node or -1
 */
ssize_t get_node_index(l_s *l, l_s *n)
{
	size_t i = 0;

	while (l)
	{
		if (l == n)
			return (i);
		l = l->next;
		i++;
	}
	return (-1);
}
