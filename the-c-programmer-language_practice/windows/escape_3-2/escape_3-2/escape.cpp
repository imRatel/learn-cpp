#include <stdio.h>

void escape(char s[], char t[])
{
	int i, k;
	i = k = 0;

	while (t[i] != '\0')
	{
		switch(t[i])
		{
		case '\n':
			s[k] = '\\';
			s[++k] = 'n';
			++k; break;
		case '\t':
			s[k] = '\\';
			s[++k] = 't';
			++k; break;
		default:
			s[k] = t[i];
			++k; break;
		}
		++i;
	}
	s[k] = '\0';
}