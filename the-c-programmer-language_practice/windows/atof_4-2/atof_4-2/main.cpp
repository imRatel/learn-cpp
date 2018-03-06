#include <stdio.h>
#define MAX 1000

double atof(char s[]);

int main()
{
	char s[MAX] = "1234.1234e-3";

	printf("\n%f", atof(s));

	return 0;
}