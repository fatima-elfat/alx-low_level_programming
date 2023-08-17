#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: head of dlist.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t r = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		r++;
	}
	return (r);
}
