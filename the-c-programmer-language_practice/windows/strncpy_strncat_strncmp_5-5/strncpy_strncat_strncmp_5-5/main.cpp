#include <stdio.h>

void strncat(char *s1, char *s2, int n);
int  strncmp(char *s1, char *s2, int n);
void strncpy(char *s1, char *s2, int n);

int main()
{
	char s1[] = "12345";
	char s2[] = "123";

	strncat(s1, s2, 2);
	printf("%s\n%s", s1,s2);

	if (strncmp(s1, s2, 2))
	{
		printf("yes\n\n\n");
	}

	strncpy(s1, s2, 2);
	printf("%s\n%s", s1, s2);

	return 0;
}