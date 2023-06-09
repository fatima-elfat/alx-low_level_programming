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
	unsigned int i;
	listint_t *temp, *node;

	if (*head == NULL || head == NULL)
	{
		return (NULL);
	}
	temp = *head;
	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		return (NULL);
	}
	node->n = n;
	if (idx == 0)
	{
		node->next = temp;
		*head = node;
		return (node);
	}
	i = 1;
	while (i < idx)
	{
		if (temp->next == NULL)
		{
			free(node);
			return (NULL);
		}
		i++;
		temp = temp->next;
	}
	if (i != idx)
	{
		free(node);
		return (NULL);
	}
	node->next = temp->next;
	temp->next = node;
	return (node);
}
