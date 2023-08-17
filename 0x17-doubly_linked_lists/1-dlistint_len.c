#include "lists.h"

/**
 * dlistint_len -  returns the number of elements in a linked dlistint_t list.
 * @h: the head of dlist.
 * Return: number of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t r = 0;

	while (h)
	{
		h = h->next;
		r++;
	}
	return (r);
}
