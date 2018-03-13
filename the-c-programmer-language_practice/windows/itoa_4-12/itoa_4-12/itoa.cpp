#include <stdio.h>

static int i;

void itoa(char s[] , int n)
{
	if (n < 0)
	{
		if (n - 1 > 0)
			n = (unsigned)n;
		else
			n = -n;
		s[i++] = '-';
	}

	if (n / 10)
	{
		itoa(s, n / 10);
	}
	s[i++] = n % 10 + '0';
}