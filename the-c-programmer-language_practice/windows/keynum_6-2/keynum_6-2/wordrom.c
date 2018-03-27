#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* wordrom(char *s)
{
	char *p;

	p = malloc(strlen(s) + 1);

	if (p != NULL)
	{
		strcpy_s(p,strlen(s) + 1, s);
	}

	return p;
}