#include "lists.h"
/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: the struct of type listint_t.
 * Return: the number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	int r;

	if (h == NULL)
		return (0);
	printf("%d\n", h->n);
	r = print_listint(h->next) + 1;
	return (r);
}
