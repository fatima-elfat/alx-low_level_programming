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
  * add_node - adds a new node at the beginning of a list_t list.
  * @head: the linked list.
  * @str: the string to add.
  * Return: the address of the new list.
  */
list_t *add_node(list_t **head, const char *str)
{
	list_t *l;

	if (head != NULL && str != NULL)
	{
		l = malloc(sizeof(list_t));
		if (l == NULL)
			return (NULL);
		l->str = strdup(str);
		l->len = _strlen_recursion(str);
		l->next = *head;
		*head = l;
	}

	return (l);
}
