#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: the head of dlist.
 * @n: the value of the node.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *r, *t;

	if (!head)
		return (NULL);
	new = malloc(sizeof(struct dlistint_s));
	if (!r)
		return (NULL);
	r->n = n;
	r->next = NULL;
	if (!*head)
	{
		*head = r;
		r->prev = NULL;
		return (r);
	}
	t = *head;
	while (t->nex)
		t = t->next;
	t->prev = t;
	t->next = r;
	return (r);
}
