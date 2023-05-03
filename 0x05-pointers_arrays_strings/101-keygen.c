#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int myrand;
	int count;
	int total;

	srand(time(NULL));
	for (count = 0, total = 3000; total > 180; count++)
	{
		myrand = (rand() % 200) + 1;
		printf("%c", myrand);
		total -= myrand;
	}
	printf("%c", total);

	return (0);
}
