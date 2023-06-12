#include "main.h"
/**
 * printM - prints the value of magic.
 * @header: information in the header.
*/
void printM(char *header)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < 16; i++)
	{
		printf("%02x", header[i]);

		if (i != 15)
			printf(" ");
		else
			printf("\n");
	}
}
/**
 * printC - prints the value of class.
 * @header: information in the header.
*/
void printC(char *header)
{
	printf("  %-35s", "Class:");
	if (header[4] == 0)
		printf("none\n");
	else if (header[4] == 1)
		printf("ELF32\n");
	else if (header[4] == 2)
		printf("ELF64\n");
	else
		printf("<unknown: %02hx>", header[4]);
}
/**
 * printD - prints the value of the data.
 * @header: information in the header.
*/
void printD(char *header)
{
	printf("  %-35s", "Data:");
	if (header[5] == 0)
		printf("none\n");
	else if (header[5] == 1)
		printf("2's complement, little endian\n");
	else if (header[5] == 2)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %02hx>", header[5]);
}
/**
 * printV - prints the value of the version.
 * @header: information in the header.
*/
void printV(char *header)
{
	printf("  %-35s", "Version:");
	printf("%d", header[6]);
	if (header[6] == 1)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}
/**
 * printO - prints the value of the OS/ABI.
 * @header: information in the header.
*/
void printO(char *header)
{
	printf("  %-35s", "OS/ABI:");
	switch (header[7])
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 1:
		printf("UNIX - HP-UX\n");
		break;
	case 2:
		printf("UNIX - NetBSD\n");
		break;
	case 3:
		printf("UNIX - Linux\n");
		break;
	case 6:
		printf("UNIX - Solaris\n");
		break;
	case 7:
		printf("UNIX - AIX\n");
		break;
	case 8:
		printf("UNIX - IRIX\n");
		break;
	case 9:
		printf("UNIX - FreeBSD\n");
		break;
	case 10:
		printf("UNIX - TRU64\n");
		break;
	case 11:
		printf("UNIX - Novell Modesto\n");
		break;
	case 12:
		printf("UNIX - OpenBSD\n");
		break;
	case 97:
		printf("ARM\n");
		break;
	/*case 255:
	*	printf("Standalone App\n");
	*	break;
	*/
	default:
		printf("<unknown: %02x>\n", header[7]);
	}
}
/**
 * printA - prints the value of the ABI.
 * @header: information in the header.
*/
void printA(char *header)
{
	printf("  %-35s%d\n", "ABI Version:", header[8]);
}
/**
 * printT - prints the value of the type.
 * @header: information in the header.
*/
void printT(char *header)
{
	int i;

	if (header[5] == 1)
	{
		i = 16;
	}
	else if (header[5] == 2)
	{
		i = 17;
	}
	printf("  %-35s", "Type:");
	switch (header[i])
	{
	case 0:
		printf("NONE (None)\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		if (i == 16)
		{
			printf("<unknown>: %02x\n", header[16]);
		}
		else
		{
			printf("<unknown>: %02x%02x\n",
					header[16], header[17]);
		}
	}
}
/**
 * printE - prints the value of the entry adress.
 * @header: information in the header.
*/
void printE(char *header)
{
	int a, b;

	printf("  %-35s0x", "Entry point address:");
	if (header[4] == 1)
		a = 0x1b;
	else if (header[4] == 2)
		a = 0x1f;
	if (header[5] == 1)
	{
		while (header[a] == 0 && a > 0x18)
		{
			a--;
		}
		printf("%x", header[a]);
		a--;
		while (a >= 0x18)
		{
			printf("%02x", (unsigned char) header[a]);
			a--;
		}
		printf("\n");
	}
	else if (header[5] == 2)
	{
		b = 0x18;
		while (header[b] == 0)
		{
			b++;
		}
		printf("%x", header[b]);
		b++;
		while (b <= a)
		{
			printf("%02x", (unsigned char) header[b]);
			b++;
		}
		printf("\n");
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
    int elf_filename, elf_header, len = 64;
	char *header;

    if (argc != 2)
	{
		dprintf(STDERR_FILENO, "ERROR: Too many arguments.\n");
		exit(98);
	}
    elf_filename = open(argv[1], O_RDONLY);
    if (elf_filename == -1)
	{
		dprintf(STDERR_FILENO,
				"ERROR: Can't open file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(char) * len);
	if (header == NULL)
	{
		close(elf_filename);
		dprintf(STDERR_FILENO,
				"ERROR: Memory allocation unsuccessful\n");
		exit(98);
	}
	elf_header = read(elf_filename, header, len);
	if (elf_header == -1)
	{
		free(header);
		close(elf_filename);
		dprintf(STDERR_FILENO,
				"ERROR: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (header[0] != 0x7f || header[1] != 'E'
			|| header[2] != 'L' || header[3] != 'F')
	{
		dprintf(STDERR_FILENO,
				"ERROR: File %s is not an ELF\n", argv[1]);
		return (98);
	}
	/* nb = header[4]*/
	printf("ELF Header:\n");
	printM(header);
	printC(header);
	printD(header);
	printV(header);
	printO(header);
	printA(header);
	printT(header);
	printE(header);
	free(header);
	close(elf_filename);
	return (0);
}
