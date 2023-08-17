#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: the head of dlist.
 * @index: he index of the node, starting from 0.
 * Return: the node and if does not exist, return NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (!head)
		return (NULL);
	while (head->next && index)
	{
		head = head->next;
		index--;
	}
	if (index)
		return (NULL);
	return (head);
}
