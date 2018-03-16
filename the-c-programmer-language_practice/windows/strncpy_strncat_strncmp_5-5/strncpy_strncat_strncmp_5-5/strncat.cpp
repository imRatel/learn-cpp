#include <stdio.h>
#include <string.h>

void strncat(char *s1, char *s2, int n)
{
	int p1, p2;
	p2 = 0;
	p1 = strlen(s1);

	if (n > strlen(s1))
	{
		printf("The number is too large!");
		return;
	}

	while (p2 < n)
	{
		*(s1 + p1) = *(s2 + p2);
		p1 = p1 + 1;
		p2 = p2 + 1;
	}

	*(s1 + p1) = '\0';
}