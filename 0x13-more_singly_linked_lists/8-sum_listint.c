#include "lists.h"
/**
 * sum_listint - returns the sum of all the data (n) of listint_t linked list.
 * @head: the input type struct listint_t .
 * Return: the sum of data n.
 */
int sum_listint(listint_t *head)
{
	int r = 0;

	if (head == NULL)
	{
		return (0);
	}
	while (head != NULL)
	{
		r += head->n;
	}
	return (r);
}
