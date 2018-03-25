#include <stdio.h>

#define MAX 100

int isnumcmp, free, dir,reverse;

int strcmp(char *p1, char *p2);
int numcmp(char *p1, char *p2);
int readline(char *p[], int maxnline);
void writeline(char *p[], int nline);
int getargv(char *argv[]);
void qsort(char *p[], int left, int right, int(*comp)(void*, void*));

int main()
{
	char *argv[100],*line[MAX];
	int argc, nline;

	argc = getargv(argv);
	nline = readline(line, MAX);
	for (int i = 1; i < argc; i++)
	{
		if (*argv[i] == '-')
		{
			for (int n = 0;*(argv[i] + n) != '\0'; n++)
			{
				switch (*(argv[i] + n))
				{
				case 'n':isnumcmp = 1; break;
				case 'r':reverse = 1; break;
				case 'd':dir = 1; break;
				case 'f':free = 1; break;
				}
			}
		}
	}
	
	qsort(line, 0, nline, (int(*)(void*, void*))(isnumcmp ? numcmp : strcmp));

	writeline(line, nline);

	return 0;
}