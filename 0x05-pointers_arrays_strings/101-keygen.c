#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - main function
 */
int main(void)
{
	int i;
	char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/";

	srand(time(NULL));
	for(i = 0; i < 41; i++) 
	{
		printf("%c", list[rand() % (sizeof list - 1)]);
	}
	return (0);
}
