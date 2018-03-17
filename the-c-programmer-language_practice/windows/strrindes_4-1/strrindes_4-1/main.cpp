#include <stdio.h>

int strrindes(char *s, char *t);

int main()
{
	char s[] = "1234512345";
	char t[] = "345";
	printf("%d", strrindes(s, t));
	return 0;
}