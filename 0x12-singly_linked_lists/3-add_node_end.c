#include "lists.h"
/**
 * _strlen_recursion - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen_recursion(const char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}

/**
  * add_node_end - adds a new node at the end of a list_t list.
  * @head: the linked list.
  * @str: the string to add.
  * Return: the address of the new list.
  */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *l1, *l2;

	if (str != NULL)
	{
		l1 = malloc(sizeof(list_t));
		if (l1 == NULL)
			return (NULL);
		l1->str = strdup(str);
		l1->len = _strlen_recursion(str);
		l1->next = NULL;
		if (*head != NULL)
		{
			l2 = *head;
			while (l2->next != NULL)
			{
				l2 = l2->next;
			}
			l2->next = l1;
			return (l2);
		}
		else
		{
			*head =  l1;
			return (l1);
		}
	}
	return (NULL);
}
