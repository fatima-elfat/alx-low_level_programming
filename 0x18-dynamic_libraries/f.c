#include <unistd.h>
#include <string.h>

int rand()
{
	static int r = -1;

	r++;
	if (r == 0 || r == 1)
		return 8;
	else if (r == 2)
		return 7;
	else if (r == 3)
		return 9;
	else if (r == 4)
		return 23;
	else if (r == 5)
		return 74;
	return r * r % 10000;
}
