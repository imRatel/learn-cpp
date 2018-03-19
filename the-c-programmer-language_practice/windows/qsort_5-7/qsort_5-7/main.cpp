#include <stdio.h>

#define MAXNLINE 5000

char *p[MAXNLINE];

void writeline(char *p[], int nline);
int readline(char *p[], int maxnline);
void qsort(char *p[], int left, int right);

int main()
{
	int nline;

	nline = readline(p, MAXNLINE);
	qsort(p, 0, nline);
	writeline(p, nline);

	return 0;
}