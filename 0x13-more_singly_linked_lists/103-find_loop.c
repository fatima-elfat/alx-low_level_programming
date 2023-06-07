#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: the input struct.
 * Return: The address of the node where the loop starts
 * , or NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{

	listint_t *a, *b;

	if (head == NULL)
	{
		return (NULL);
	}
	a = head;
	b = a;
	while (a && b)
	{
		a = a->next;
		b = b->next->next;

		if (a == b)
		{
			a = b;
			while (a != b)
			{
				a = a->next;
				b = b->next;
			}
			return ((a->next));
		}
	}
	return (NULL);
}
