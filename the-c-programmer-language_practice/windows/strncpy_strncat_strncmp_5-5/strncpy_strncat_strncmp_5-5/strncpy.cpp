#include <stdio.h>
#include <string.h>

void strncpy(char *s1, char *s2, int n)
{
	int p = 0;

	if (n > strlen(s2))
	{
		printf("The number is too large!");
		return;
	}

	while (p < n)
	{
		*(s1 + p) = *(s2 + p);
		p = p + 1;
	}
	*(s1 + p) = '\0';
}