#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: the head of dlist.
 * @idx:the index of the list where the new node should be added.
 * @n: the value at node.
 * Return: the address of the new node, or NULL if it failed. if it is
 * not possible to add the new node at index idx,
 * do not add the new node and return NULL.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *r, *t;

	if (idx == 0)
		return (add_dnodeint(h, n));
	if (!h)
		return (NULL);
	t = *h;
	while (t->next && idx)
	{
		t = t->next;
		idx--;
		if (!idx)
		{
			r = malloc(sizeof(struct dlistint_s));
			if (!r)
				return (NULL);
			r->n = n;
			r->prev = t->prev;
			t->prev->next = r;
			r->next = t;
			t->prev = r;
			return (r);
		}
	}
	if (idx != 1)
		return (NULL);
	return (add_dnodeint_end(h, n));
}
