#include "lists.h"
/**
 * delete_nodeint_at_index - deletes idx node of a listint_t linked list.
 * @head: a list of struct listint_t.
 * @index: index of node to delete.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp1, *temp2;

	if (*head == NULL)
	{
		return (-1);
	}
	temp1 = *head;
	if (index == 0)
	{
		*head = temp1->next;
		free(temp1);
		return (1);
	}
	while (i != (index - 1) || temp1->next != NULL)
	{
		i++;
		temp1 = temp1->next;
	}
	if (i == (index - 1))
	{
		if (temp1->next == NULL)
		{
			return (-1);
		}
		temp2 = temp1->next;
		temp1->next = (temp1->next)->next;
		free(temp2);
		return (1);
	}
	return (-1);
}
