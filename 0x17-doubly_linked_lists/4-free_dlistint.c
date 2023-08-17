#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head:the head of the dlist.
 */
void free_dlistint(dlistint_t *head)
{
	if (!head)
		return;
	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
