#include <stdio.h>
#include <string.h>

int  strncmp(char *s1, char *s2, int n)
{
	int p = 0;

	if (n > strlen(s1) || n > strlen(s2))
	{
		printf("The number is too large!");
		return 0;
	}

	while (p < n && *(s1 + p) == *(s2 + p))
	{
		p = p + 1;
	}

	if (p == n)
	{
		return 1;
	}
	return 0;
}