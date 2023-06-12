#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}

/**
 * create_file - creates a file. The created file
 * must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * @filename: the name of the file to create.
 * @text_content: is a NULL terminated string to write.
 * if text_content is NULL create an empty file.
 * Return: 1 on success. And -1 on failure if the file
 * can not be opened or read, if filename is NULL,
 * if write fails or does not write the expe.
*/
int create_file(const char *filename, char *text_content)
{
	int a, r, len;

	if (filename == NULL)
	{
		return (-1);
	}
	len = _strlen_recursion(text_content);
	a = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (a == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		r = write(a, text_content, len);
		if (r != len || r == -1)
		{
			return (-1);
		}
	}
	close(a);
	return (1);
}
