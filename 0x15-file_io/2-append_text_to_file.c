#include "main.h"
/**
 * _strlen - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen(s));
}
/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name of the file to create.
 * @text_content: is a NULL terminated string to write. If it is NULL,
 * do not add anything to the file. r 1 if the file exists
 * and -1 if it does not exist or if you do not have
 * the required permissions to write in.
 * Return: 1 on success. And -1 on failure if the file
 * can not be opened or read, if filename is NULL,
 * if write fails or does not write the expe.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int a, r, len;

	if (filename == NULL)
	{
		return (-1);
	}
	a = open(filename, O_WRONLY | O_APPEND);
	if (a == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		len = _strlen(text_content);
		r = write(a, text_content, len);
		if (r == -1 || r != len)
			return (-1);
	}
	close(a);
	return (1);
}
