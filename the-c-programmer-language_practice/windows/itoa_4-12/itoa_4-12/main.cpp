#include <stdio.h>

void itoa(char s[], int n);

int main()
{
	char s[100];
	int n = 123456;
	itoa(s, n);
	printf("%s", s);

	return 0;
}