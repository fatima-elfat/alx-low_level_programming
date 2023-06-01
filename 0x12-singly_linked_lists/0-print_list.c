#include "lists.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
/**
 * _puts - prints a string followed by a new line
 * @s: string to print.
 * Return: length of string.
 */
int _puts(char *s)
{
	while (*s != '\0')
		_putchar(*s++);

	_putchar('\n');
	return (_strlen(s));
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: the input linked list.
 * Return: the number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t r = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			_puts("[0] (nil)\n");
		else
		{
			_putchar("[");
		}
		h = h->next;
		r++;
	}
	return (r);
}
