#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - main function
 */
int main(void)
{
	char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/\|";

	srand(time(NULL));
	for (int i = 0; i < 4; i++) 
	{
		printf("%c", list[rand() % (sizeof list - 1)]);
	}
	return (0);
}
