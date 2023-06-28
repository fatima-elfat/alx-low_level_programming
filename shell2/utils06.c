#include "shell.h"
/**
 * delete_node_at_index - deletes node.
 * @l: the head of linked list(adress).
 * @i: the index of the node that
 * needs to be deleted
 * Return: 1.
 */
int delete_node_at_index(l_s **l, unsigned int i)
{
	unsigned int i = 0;
	l_s *ipnode, *node;

	if (!l || !*l)
		return (0);

	if (i == 0)
	{
		node = *l;
		*l = (*l)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *l;
	while (node != NULL)
	{
		if (i == i)
		{
			ipnode->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		i++;
		ipnode = node;
		node = node->next;
	}
	return (0);
}
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: the pointer to the memory previously allocated.
 * @old_size: the size of space of ptr.
 * @new_size: the new size of the new memory.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);
	if (!(old_size < new_size))
		old_size = new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
/**
 * _strfree - frees a string in list of strings.
 * @s: the string.
 */
void _strfree(char **s)
{
	char **r = s;

	if (!s)
		return;
	while (*s)
		free(*s++);
	free(r);
}
/**
 * freel - frees a list.
 * @head: the heard of linked list.
 */
void freel(l_s **head)
{
	l_s *l, *nl, *hl;

	if (!head || !*head)
		return;
	hl = *head;
	l = hl;
	while (l)
	{
		nl = l->next;
		free(l->s);
		free(l);
		l = nl;
	}
	*head = NULL;
}