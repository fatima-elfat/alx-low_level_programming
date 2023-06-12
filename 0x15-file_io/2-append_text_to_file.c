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
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name of the file to create.
 * @text_content: is a NULL terminated string to write.
 * If text_content is NULL, do not add anything to the file.
 * r 1 if the file exists and -1 if it does not exist
 * or if you do not have the required permissions to write in.
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
	len = _strlen_recursion(text_content);
	a = open(filename, O_WRONLY | O_APPEND);
	if (a == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		close(a);
		return (-1);
	}
	r = write(a, text_content, len);
	if(close(a) == -1 || r != len)
	{
		return (-1);
	}
	return (r);
}