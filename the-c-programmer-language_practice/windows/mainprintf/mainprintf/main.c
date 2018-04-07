#include <stdio.h>

void mainprintf(char *fmt, ...);

int main()
{
	int a = 10;
	char *string = "12345";
	float b = 1.23;

	mainprintf("%d\n%f\n%s\n", a ,b, string);

	return 0;
}