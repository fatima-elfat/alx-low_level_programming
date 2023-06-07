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
			return (a->next);
		}
	}
	return (NULL);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: the input struct.
 * Return: the number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0;
	int k;
	const listint_t *temp;
	listint_t *loop;

	if (head == NULL)
	{
		exit(98);
	}
	loop = whereisloop((listint_t *) head);
	if (loop == NULL)
	{
		temp = head;
		while (temp)
		{
			printf("[%p] %d\n", (void *)temp, temp->n);
			i++;
			temp = temp->next;
		}
	}
	else
	{
		k = 1;
		for (i = 0; head != NULL && k; i++)
		{
			if (head == loop)
				k = 0;
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		if (loop != NULL)
		{
			printf("-> [%p] %d\n", (void *) head, head->n);
		}
	}
	return (i);
}
