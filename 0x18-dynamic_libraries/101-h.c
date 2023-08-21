#include <string.h>
#include <unistd.h>
int rand()
{
	static int r = -1;

	r++;
	if (r == 0 || r == 1)
		return 8;
	if (r == 2)
		return 7;
	if (r == 3)
		return 9;
	if (r == 4)
		return 23;
	if (r == 5)
		return 74;
	return r * r % 30000;
}
