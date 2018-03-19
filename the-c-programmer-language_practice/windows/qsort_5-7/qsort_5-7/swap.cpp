#include <stdio.h>

void swap(char *p[], int i, int j)
{
	char *temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}