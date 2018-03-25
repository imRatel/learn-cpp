#include <stdio.h>

#define MAXROM 50000

static char rom[MAXROM];
static char *now = rom;

char* alloc(int n)	//·ÖÅä´¢´æ¿Õ¼ä
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

void afree(char *p)	//ÊÍ·Å´¢´æ¿Õ¼ä
{
	if (p > rom && p < rom + MAXROM)
	{
		now = p;
		return;
	}

	printf("error: The pointer is not in range!\n");
}