#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: the struct.
 * Return: a pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp1, *temp2;

	if (head == NULL || *head == NULL)
		return (NULL);
	temp1 = NULL;
	while (*head != NULL)
	{
		temp2 = (*head)->next;
		(*head)->next = temp1;
		temp1 = *head; 
		*head = temp2;
	}
	*head = temp1;
	return (*head);
}
