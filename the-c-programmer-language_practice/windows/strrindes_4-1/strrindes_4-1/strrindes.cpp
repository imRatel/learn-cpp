#include <stdio.h>
#include <string.h>

int strrindes(char s[], char t[])
{
	int n_s, n_t;
	n_s = n_t = 0;

	for (n_s = strlen(s) - 1; n_s >= 0; n_s--)
	{
		for (n_t = strlen(t) - 1; s[n_s] == t[n_t]; n_t--, n_s--)
			;
		if (n_t < 0)
			return (n_s += 2);
	}
	return -1;

}