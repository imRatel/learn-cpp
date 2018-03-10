#include <stdio.h>
#define MAX 100

void getline(char line[])
{
	int i, ch;
	i = ch = 0;
	while ((ch = getchar()) != EOF)
	{
		line[i] = ch;
		++i;
	}

	line[i++] = EOF;
	line[i] = '\0';
}