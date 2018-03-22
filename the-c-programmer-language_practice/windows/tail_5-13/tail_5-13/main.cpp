#include <stdio.h>

#define MAX 100

int readline(char *p[], int maxnline, char alloc[]);
int tail(int argc, char* argv[], char* line[], int nline);

int main()
{
	char romargv[MAX],rom[MAX*MAX];
	char *lines[MAX];
	int nlines;
	char *argv[MAX];
	int argc;

	argc = readline(argv, MAX, romargv);
	nlines = readline(lines, MAX, rom);

	tail(argc, argv, lines, nlines);

	return 0;
}