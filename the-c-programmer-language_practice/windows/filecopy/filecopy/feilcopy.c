#include <stdio.h>
#include <stdlib.h>

#define MAX 100

FILE* filecopy(FILE *fp1, FILE *fp2)
{
	char ch;
	if (fp1 == NULL || fp2 == NULL)
	{
		exit(1);
	}

	while ((ch == getc(fp1) != EOF))
	{
		putc(ch,fp2);
	}
	exit(0);
}