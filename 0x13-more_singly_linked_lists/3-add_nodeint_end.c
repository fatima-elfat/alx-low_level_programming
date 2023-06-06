#include "lists.h"
/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list.
 * @head: the input list of structs of type listint_t.
 * @n: the value of the member n in the struct.
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp;

	if (*head == NULL)
	{
		*head = malloc(sizeof(listint_t));
		if (*head == NULL)
		{
			return (NULL);
		}
		(*head)->n = n;
		(*head)->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(listint_t));
		if (temp == NULL)
		{
			return (NULL);
		}
		temp->n = n;
		temp->next = NULL;
		while ((*head)->next != NULL)
		{
			*head = (*head)->next;
		}
		(*head)->next = temp;
	}
	return (*head);
}
