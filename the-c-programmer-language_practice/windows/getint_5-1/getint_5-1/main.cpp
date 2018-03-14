#include <stdio.h>

double getint(double *num);

int main()
{
	double n = 0;

	getint(&n);
	printf("%f", n);

	return 0;
}