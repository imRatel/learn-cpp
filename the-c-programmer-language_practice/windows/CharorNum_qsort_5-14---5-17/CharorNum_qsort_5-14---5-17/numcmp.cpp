#include <stdio.h>
#include <stdlib.h>

int numcmp(char *p1, char *p2)
{
	double n1, n2;
	n1 = atof(p1);
	n2 = atof(p2);

	return n1 - n2;
}