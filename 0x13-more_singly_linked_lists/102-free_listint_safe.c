#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: the input struct.
 * Return: the size of the list that was free’d.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	int k;
	listint_t *temp, *loop;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}
	loop = whereisloop((listint_t *) *h);
	k = 1;
	if (!loop)
	{
		for (i = 0; *h != NULL && k; i++)
		{
			temp = (*h)->next;
			if (*h == loop)
			{
				k = 0;
				temp = temp->next;
			}
			free(temp);
		}
	}
	else
	{
		temp = (*h)->next;
		(*h)->next = NULL;
		free(temp);
	}
	*h = NULL;
	return (i);
}
