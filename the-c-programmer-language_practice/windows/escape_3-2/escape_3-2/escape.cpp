#include <stdio.h>

void escape(char *s, char *t)
{
	int i, k;
	i = k = 0;

	while (*(t + i) != '\0')
	{
		switch(*(t + i))
		{
		case '\n':
			*(s + k) = '\\';
			k = k + 1;
			*(s + k) = 'n';
			break;
		case '\t':
			*(s + k) = '\\';
			k = k + 1;
			*(s + k) = 't';
			break;
		default:
			*(s + k) = *(t + i);
			break;

			
		}
		k = k + 1;
		++i;
	}
	*(s + k) = '\0';
}