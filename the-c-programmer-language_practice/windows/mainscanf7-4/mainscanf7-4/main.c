#include <stdio.h>

void mainscanf(char *fmt, ...);


int main()
{
	int i;
	char c;
	char s[100];
	double d;

	mainscanf("%d%f%s%c", &i, &d, s, &c);
	printf("%d\n%f\n%s\n%c\n", i, d, s, c);

	return 0;
}