#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - main function
 */
int main(void)
{
	char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/";
	int i;

	srand(time(NULL));
	for (i = 0; i < 4; i++) 
	{
		printf("%c", list[rand() % (sizeof list - 1)]);
	}
	return (0);
}
