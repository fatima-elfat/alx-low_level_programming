#include "lists.h"
/**
 * pop_listint - deletes the head node of a listint_t linked list, and returns
 * the head node’s data (n).
 * @head: the input struct listint_t .
 * Return: the head node’s data (n), if the linked list is empty return 0.
 */
int pop_listint(listint_t **head)
{
	int r;
	listint_t temp;

	temp = *head;
	if (temp == NULL)
	{
		return (0);
	}
	r = temp->n;
	*head = temp->next;
	free(temp);
	return (r);
}
