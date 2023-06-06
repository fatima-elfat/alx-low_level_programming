#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: the input list of type struct listint_t.
 * @idx: the index of the list where the new node should be added.
 * @n: the value of member (n).
 * Return:the address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *temp, *node;

	if (*head == NULL)
	{
		return (NULL);
	}
	temp = *head;
	while (i != idx || temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	if (i == idx)
	{
		node = temp;
		temp->n = n;
		temp->next = node;
		return (temp);
	}
	return (NULL);
}