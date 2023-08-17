#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list.
 * @head: the head of dlist.
 * @index: the index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *t = *head;

	if (head || *head)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(t);
		return (1);
	}
	while ((index--) && t->next)
		t = t->next;
	if (index > 1 || !t->next)
		return (-1);
	t->prev->next = t->next;
	if (t->next)
		t->next->prev = t->prev;
	free(t);
	return (1);
}
