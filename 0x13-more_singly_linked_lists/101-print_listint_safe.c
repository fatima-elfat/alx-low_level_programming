#include "lists.h"
/**
 * isloop - detects loops using Floyd’s Cycle-Finding Algorithm.
 * @head: the input struct.
 * @num: the number of nodes.
 * Return: 1 for true.
 */
int isloop(const listint_t *head, size_t *num)
{
	int r = 0;
	const listint_t *a = head, *b = head;

	*num = 0;
	while (a && b && b->next)
	{
		a = a->next;
		b = (b->next)->next;
		*num += 1;
		if (b == a)
		{
			r = 1;
			a = head;
			while (a != b)
			{
				a = a->next;
				b = b->next;
				*num += 1;
			}
			a = a->next;
			while (a != b)
			{
				a = a->next;
				*num += 1;
			}
		}
		a = a->next;
		b = (b->next)->next;
	}
	return (r);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: the input struct.
 * Return: the number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	int j;
	size_t num, i = 0, k;
	const listint_t *temp;

	if (head == NULL)
	{
		exit(98);
	}
	j = isloop(head, &num);
	if (j == 0)
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
		for (k = 0; k < num; k++)
		{
			printf("[%p] %d\n", (void *)temp, temp->n);
			i++;
			temp = temp->next;
		}
	}
	return (i);
}
