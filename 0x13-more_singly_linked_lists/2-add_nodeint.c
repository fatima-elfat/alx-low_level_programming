#include "list.h"
/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: a list of structs of type listint_t.
 * @n: the value of the member n in struct listint_t.
 * Return: the adress of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *temp;

	if (*head == NULL)
	{
		*head = malloc(sizeof(listint_t));
		if (*head == NULL)
		{
			return (NULL);
		}
		*head->n = n;
		*head->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(listint_t));
		if (temp == NULL)
		{
			return (NULL);
		}
		temp->n = n;
		temp->next = *head;
		*head = temp;
	}
	return (*head);
}
