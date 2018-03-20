#include <stdio.h>

#define MAXNLINE 5000
#define MAXLEN 100
char *p[MAXNLINE];
char alloc[MAXNLINE * MAXLEN];

void writeline(char *p[], int nline);
int readline(char *p[], int maxnline,char alloc[]);
void qsort(char *p[], int left, int right);

int main()
{
	int nline;

	nline = readline(p, MAXNLINE,alloc);
	qsort(p, 0, nline);
	writeline(p, nline);

	return 0;
}