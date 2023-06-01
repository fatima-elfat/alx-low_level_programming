#include "lists.h"

/**
  * list_len - returns the number of elements in a linked list_t list.
  * @h: the input linked list.
  * Return: the number of elements in a linked list_t.
  */
size_t list_len(const list_t *h)
{
	size_t r = 0;

	while (h != NULL)
	{
		h = h->next;
		r++;
	}

	return (r);
}
