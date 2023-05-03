#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int myrand;
	int count;
	int total;

	srand(time(NULL));
	for (count = 0, total = 5000; total > 200; count++)
	{
		myrand = (rand() % 255) + 1;
		printf("%c", myrand);
		total -= myrand;
	}
	printf("%c", total);

	return (0);
}
