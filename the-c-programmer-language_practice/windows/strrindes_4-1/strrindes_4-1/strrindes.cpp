#include <stdio.h>
#include <string.h>

int strrindes(char *s, char *t)
{
	int p_s, p_t;
	p_s = p_t = 0;

	for (p_s = strlen(s) - 1; p_s >= 0; p_s--)
	{
		for (p_t = strlen(t) - 1; *(s + p_s) == *(t + p_t); p_t--, p_s--)
			;
		if (p_t < 0)
			return (p_s += 2);
	}
	return -1;

}