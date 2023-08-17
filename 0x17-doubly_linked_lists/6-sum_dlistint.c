#include "lists.h"
/**
 * sum_dlistint - returns the sum of all
 * the data (n) of a dlistint_t linked list.
 * @head: the head of dlist.
 * Return: the sum and if the list is empty, return 0.
 */
int sum_dlistint(dlistint_t *head)
{
	int r = 0;

	if (!head)
		return (r);
	while (head)
	{
		r += head->n;
		head = head->next;
	}
	return (r);
}
