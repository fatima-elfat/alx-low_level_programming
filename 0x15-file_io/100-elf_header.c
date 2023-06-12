#include "main.h"
/**
 * main - entry function.
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success.
*/
int main(int argc, char *argv[])
{
    int elf_filename;

    if (argc != 2)
	{
		dprintf(STDERR_FILENO, "ERROR: Too many arguments.\n");
		exit(98);
	}
    elf_filename = open(argv[1], O_RDONLY);
    if (elf_filename == -1)
	{
		dprintf(STDERR_FILENO, "ERROR: Can't read from file %s\n", argv[1]);
		exit(98);
	}
}