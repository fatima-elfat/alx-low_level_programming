#include "lists.h"
/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: the input of type struct listint_t.
 * Return: the number of elements.
 */
size_t listint_len(const listint_t *h)
{
	int r;

	if (h == NULL)
		return (0);
	if (h->next == NULL)
	{
		return (1);
	}
	r = listint_len(h->next) + 1;
	return (r);
}
