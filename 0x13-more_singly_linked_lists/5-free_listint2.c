#include "lists.h"
/**
 * free_listint2 - frees a listint_t list. The function sets the head to NULL.
 * @head: the struct listint_t.
 */
void free_listint2(listint_t *head)
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
