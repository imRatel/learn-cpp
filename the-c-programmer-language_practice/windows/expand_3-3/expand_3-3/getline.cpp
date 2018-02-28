#include <stdio.h>

void getline(char line[])
{
	int i, ch;
	i = ch = 0;
	while ((ch = getchar()) != '`')
	{
		line[i] = ch;
		++i;
	}

	line[i] = '\0';
}