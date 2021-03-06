#include <stdio.h>

#define MAXLEN 1000

int getline(char *line, int maxlen);
char* alloc(int n);

void strcpy(char *s1, char *s2)
{
	while ((*s1 = *s2) != '\0')
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
	}

	*s1 = '\0';
}

int readline(char *p[], int maxnline)
{
	int len, nline = 0;
	char line[MAXLEN];

	while ((len = getline(line, MAXLEN)) != 0)//记录当前字符串指针到指针数组中
	{
		line[len - 1] = '\0';
		p[nline] = alloc(len);
		strcpy(p[nline], line);

		if (nline == maxnline - 1)
		{
			printf("error: The lines is too mach!");
			return nline - 1;
		}

		nline = nline + 1;
	}

	return nline - 1;


}