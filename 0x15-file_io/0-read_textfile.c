#include "main.h"
/**
 * read_textfile - reads a text file and prints it to
 * the POSIX standard output.
 * @filename: the name of the file.
 * @letters: the number of letters it should read and print.
 * Return: the actual number of letters it could read and print.
 * Or return 0 if the file can not be opened or read,
 * if filename is NULL, if write fails or does not write
 * the expected amount of bytes.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int a, b, r;
	char *c;

	if (filename == NULL || letters == 0)
	{
		return (0);
	}
	c = malloc(sizeof(char) * letters);
	if (c == NULL)
	{
		return (0);
	}
	a = open(filename, O_RDONLY);
	if (a == -1)
	{
		free(c);
		return (0);
	}
	b = read(a, c, letters);
	if (b == -1)
	{
		free(c);
		close(a);
		return (0);
	}
	r = write(STDOUT_FILENO, c, letters);
	free(c);
	close(a);
	if (r == -1)
	{
		return (0);
	}
	return (b);
}
