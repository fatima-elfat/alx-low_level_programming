#include "main.h"
/**
 * error_cp - prints the convinent error
 * and exit with the proper value.
 * @code: the code error.
 * @filenames: the filename that raised the error.
 * @fileD: the file descriptor.
 * Return: 0 on success
 **/
int error_cp(int code, char *filenames, int fileD)
{
	switch (code)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(code);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filenames);
		exit(code);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filenames);
		exit(code);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileD);
		exit(code);
	default:
		return (0);
	}
}
/**
 * main - entry function.
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	char buffer[1024];
	int file_from, file_to;
	int len1 = 0, len2 = 0;

	if (argc != 3)
	{
		error_cp( 97, NULL, 0);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		error_cp( 98, argv[1], 0);
	}
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		error_cp( 99, argv[2], 0);
	}
	while(read(file_from, buffer, 1024) != 0)
	{
		len1 = read(file_from, buffer, 1024);
		if (len1 == -1)
		{
			error_cp( 98, argv[1], file_from);
		}
		len2 = read(file_to, buffer, len1);
		if (len2 == -1 || len2 != len1)
		{
			error_cp( 99, argv[2], file_to);
		}
	}
	if (close(file_from) == -1)
	{
		error_cp( 100, NULL, file_from);
	}
	if (close(file_to) == -1)
	{
		error_cp( 100, NULL, file_to);
	}
	return (0);
}