#include <stdio.h>
#define MAX 1000

void getline(char line[])
{
	int i, ch;
	i = ch = 0;
	while ((ch = getchar()) != '\n')
	{
		line[i] = ch;
		++i;
	}

	line[i] = '\0';
}