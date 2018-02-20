#include <stdio.h>
#define MAX 1000
#define IN 1
#define OUT 0

int any(char s1[], char s2[])
{
	int n_1, n_2, state, first;
	n_1 = n_2 = state = first = 0;

	while (state != IN && s1[n_1] != '\0')
	{
		while (state != IN && s2[n_2] != '\0')
		{
			if (s1[n_1] == s2[n_2])
			{
				first = n_1 + 1;
				state = IN;
			}
			else
				++n_2;
		}
		++n_1;
		n_2 = 0;
	}

	if (state == IN)
		return first;
	else
		return -1;
}