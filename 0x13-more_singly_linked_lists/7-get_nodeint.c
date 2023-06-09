#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: the struct listint_t.
 * @index: the index of the node.
 * Return: nth node of a listint_t equal to index.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}
	while (i < index)
	{
		if (head->next == NULL)
		{
			return (NULL);
		}
		head = head->next;
		i++;
	}
	return (head);
}
