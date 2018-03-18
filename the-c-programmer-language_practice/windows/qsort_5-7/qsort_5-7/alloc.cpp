#include <stdio.h>

#define MAXROM 500000

static int rom[MAXROM];
static int *now = rom;

int* alloc(int n)
{
	if (n > 0 && n < rom + MAXROM - now)
	{
		now = now + n;
		return now - n;
	}

	if (n < 0)
	{
		printf("error: The number is wrong!\n");
	}
	else
	{
		printf("error: The number si too large!\n");
	}
	return 0;
}

void afree(int *p)
{
	if (p > rom && p < rom + MAXROM)
	{
		now = p;
		return;
	}

	printf("error: The pointer is not in range!\n");
}