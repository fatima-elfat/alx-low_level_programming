#include "lists.h"
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: the head of dlist.
 * @n: the value of the node.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *r;

	if (!head)
		return (NULL);
	r = malloc(sizeof(struct dlistint_s));
	if (!r)
		return (NULL);
	r->n = n;
	r->prev = NULL;
	if (!*head)
	{
		*head = r;
		r->next = NULL;
		return (r);
	}
	(*head)->prev = r;
	r->next = *head;
	*head = r;
	return (r);
}
