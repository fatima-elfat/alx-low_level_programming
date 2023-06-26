#include "shell.h"

char *isinpath(char *s, l_u *e)
{
	char *r, *t, **tk, *pval;
	int i =0;

	r = NULL;
	t = NULL;
	if (!access(s, F_OK))
	{
		r = s;
		return(r);
	}
	else
	{
		printf("utils04.c: start\n");
		pval = _getenvval("PATH", e);
		printf("utils04.c: pval= %s\n", pval);
		tk = _strtok(pval, ':');
		free(pval);
		while (tk[i])
		{
			t = _strcat(tk[i], "/");
			r = _strcat(t, s);
			i++;
			if (!access(r, F_OK))
			{
				_freetok(tk);
			}
			return(r);
		}
		free(t);
		free(r);
	}
	return (s);
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
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: the linked list.
 * @str: the string to add.
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
