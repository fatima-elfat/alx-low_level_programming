#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}
/**
 * _strcpy - copy the string
 * @dest: destination of the string
 * @src: souece of the string
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * 
*/
ssize_t _getline(char *s)
{
	ssize_t r, fd = 1, len = BUF_SIZE, j = 0;
	static ssize_t counter;
	char *buffer;

	counter = checkcounter(counter);
	if (counter == -1)
		return (-1);
	buffer =malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (-1);
	while (j == 0)
	{
		fd = read(STDIN_FILENO, buffer, len - 1);
		if (fd == -1)
		{
			free(buffer);
			return (-1); }
		if (counter == 0 && fd != 0)
			counter += fd;
		if (counter != 0 && fd == 0)
		{
			counter++;
			j = 1; }}
	if (counter > len)
		buffer = _realloc(buffer, len, counter + 1);
	buffer[counter] = '\n';
	buffer[counter + 1] = '\0';
	if (s == NULL)
	{
		s = malloc(sizeof(char) * counter + 1);
		if (s == NULL)
			return (-1);
	}
	_strcpy(s, buffer);
	free(buffer);
	r = counter;
	counter = 0;
	return (r);
}
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size of space of ptr.
 * @new_size: new size of the new memory.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *p;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
	{
		i = 0;
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		while (i < old_size)
		{
			((char *)p)[i] = ((char *)ptr)[i];
			i++;
		}
		free(ptr);
		return (p); }
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	while (i < new_size)
	{
		((char *)p)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (p);
}
