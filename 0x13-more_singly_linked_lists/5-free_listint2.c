#include "lists.h"
/**
 * free_listint2 - frees a listint_t list. The function sets the head to NULL.
 * @head: the struct listint_t.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp1, *temp2;

	if (*head == NULL || head == NULL)
	{
		return;
	}
	temp1 = *head;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	*head = NULL;
}
