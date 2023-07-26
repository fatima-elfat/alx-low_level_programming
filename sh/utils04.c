#include "shell.h"
/**
 * isinpath - ...
 * @s: ...
 * @e: ...
 * Return: ...
 */
char *isinpath(char *s, l_u *e)
{
	char *r, **tk1, *pval;
	int i = 0;

	r = malloc(_strlen(s) + 1);
	if (!access(s, F_OK))
	{
		r = s;
		return (r);
	}
	else
	{
		pval = _getenvval("PATH", e);
		tk1 = _strtok(pval, ":");
		if (!r)
			return (NULL);
		free(pval);
		while (tk1[i])
		{
			_realloc(r, (_strlen(s) + 1), (_strlen(tk1[i]) + _strlen(s) + 2));
			_strcat(r, tk1[i]);
			_strcat(r, "/");
			_strcat(r, s);
			i++;
			if (!access(r, F_OK))
			{
				_freetok(tk1);
			}
			return (r);
		}
		free(r);
	}
	return (s);
}


/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: the linked list.
 * @s1: the string to add.
 * @s2: ...
 * Return: the address of the new list.
 */
l_u *add_node(l_u **head, char *s1, char *s2)
{
	l_u *l;

	if (head != NULL && s1 != NULL && s2 != NULL)
	{
		l = malloc(sizeof(l_u));
		if (l == NULL)
			return (NULL);
		l->s1 = s1;
		l->s2 = s2;
		l->next = *head;
		*head = l;
	}
	return (*head);
}
/**
 * _atoi - convert string to int
 * @s: string to convert
 * Return: integer
 */

int _atoi(char *s)
{
	int l, m, n;
	int b = 0;

	l = _strlen(s);
	n = 1;

	for (m = 0; m < l; m++)
	{
		if (s[m] == '-')
		{
			n *= -1;
		}
		else if (s[m] >= '0' && s[m] <= '9')
		{
			if (b != 0)
			{
				b *= 10;
			}
			b += s[m] - '0';
		}
		else if (b != 0)
		{
			break;
		}
	}
	return (n * b);
}
/**
 * _calloc -  allocates memory for an array
 * and sets it to zero, using malloc.
 * @nmemb: the number of elements.
 * @size: size of byte.
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i, a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	a = nmemb * size;
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
		p[i] = 0;
	return (p);
}