#include <stdio.h>
#include <stdlib.h>

/**
 * main - ...
 *
 * @ac: ...
 * @av: ...
 *
 * Return: ...
 */
int main(int ac, char *av[])
{
	int counter, r, t, len = 0;
	char *user_n = av[1], key_pass[7];
	long l_n[] = {0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850};
	char *s1 = (char *) l_n, *s2;

	if (ac != 2)
		return (1);
	for (s2 = user_n; *s2; s2++)
		len++;
	/*f1*/
	key_pass[0] = s1[(len ^ 0x3b) & 0x3f];
	/*f2*/
	for (s2 = user_n, t = 0; *s2; s2++)
		t += *s2;
	key_pass[1] = s1[(t ^ 0x4f) & 0x3f];
	/*f3*/
	for (s2 = user_n, t = 1; *s2; s2++)
		t *= *s2;
	key_pass[2] = s1[(t ^ 0x55) & 0x3f];
	/*f4*/
	for (s2 = user_n, t = *s2; *s2; s2++)
		if (t < *s2)
			t = *s2;
	srand(t ^ 0xe);
	key_pass[3] = s1[rand() & 0x3f];
	/*f5*/
	for (s2 = user_n, t = 0; *s2; s2++)
		t += *s2 * *s2;
	key_pass[4] = s1[(t ^ 0xef) & 0x3f];
	/*f6*/
	for (t = *user_n, counter = 0; counter < t; counter++)
		r = rand();
	key_pass[5] = s1[(r ^ 0xe5) & 0x3f];
	key_pass[6] = '\0';
	printf("%s", key_pass);
	return (0);
}
