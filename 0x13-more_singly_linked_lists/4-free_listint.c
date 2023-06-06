#include "lists.h"
/**
 * free_listint - frees a listint_t list.
 * @head: the struct listint_t.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	if (head == NULL)
	{
		return (NULL);
	}
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
