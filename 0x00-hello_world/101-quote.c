#include <stdio.h>
#include <unistd.h>

/**
 *main - Function main
 *Return: Value of 1
 *
 */

int main(void)
{
	char m[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1, m, sizeof(m) - 1);
	return (1);
}
