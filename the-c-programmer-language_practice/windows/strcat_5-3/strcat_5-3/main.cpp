#include <stdio.h>

void strcat(char *s1, char *s2);

int main()
{
	char s1[] = "123";
	char s2[] = "456";

	strcat(s1, s2);
	printf("%s", s1);
	return 0;

}