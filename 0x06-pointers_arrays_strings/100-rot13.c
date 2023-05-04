#include "main.h"

/**
 * rot13 - encode string using rot13
 * @s: string to encode
 * Return: encoded string
 */

char *rot13(char *s)
{

	int i, j;
	int li[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		     'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		     'W', 'X', 'Y', 'Z'};
	int lo[53] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		     'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		     'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
		     'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		     'J', 'K', 'L', 'M'};

	for (i = 0; s[i] != '\0'; i++)
	{

		for (j = 0; j < 53; j++)
		{
			if (s[i] == li[j])
				s[i] = lo[j];
		}
	}

	return (s);
}
