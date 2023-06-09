#include "lists.h"
/**
 * free_list - frees a list_t list.
 * @head: list
 */
void free_list(list_t *head)
{
	if (head != NULL)
	{
		free_list(head->next);
		free(head->str);
		free(head);
	}
	else
		return;
}
