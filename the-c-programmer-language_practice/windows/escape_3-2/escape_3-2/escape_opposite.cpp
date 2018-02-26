#include <stdio.h>

void escape_opposite(char s[], char t[])
{
	int i, k;
	i = k = 0;

	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\\':
			switch (t[++i])
			{
			case 'n':
				s[k] = '\n';
				++k; break;
			case 't':
				s[k] = '\t';
				++k; break;
			default:
				s[k] = t[i - 1];
				s[k] = t[i];
				++k; break;
			}
			break;
		default:
			s[k] = t[i];
			++k; break;
		}
		++i;
	}
	s[k] = '\0';
}