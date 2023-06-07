#include "lists.h"
/**
 * whereisloop - detects loops using Floyd’s Cycle-Finding Algorithm.
 * @head: the input struct.
 * Return: node of loop or null.
 */
listint_t *whereisloop(listint_t *head)
{
	listint_t *a, *b;

	a = head;
	b = a;
	while (a && b && b->next)
	{
		a = a->next;
		b = (b->next)->next;
		if (b == a)
		{
			a = b;
			while (a != b)
			{
				a = a->next;
				b = b->next;
			}
			return (a);
		}
	}
	return (NULL);
}
/**
 * frees a listint_t list.
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
	loop = whereisloop((listint_t *) head);
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
				free(temp);
			}
			free(*h);
		}
	}
	else
	{
		temp = *h->next;
		*h->next = NULL;
		free(temp);
	}
	*h = NULL;
	return (i);
}
