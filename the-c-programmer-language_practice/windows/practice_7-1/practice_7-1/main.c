#include <stdio.h>
#include <string.h>

#define MAX 100

int tolow(int argc, char *argv[], char c);
int getargv(char *argv[]);

int main()
{
	int argc,c;
	char *argv[MAX];
	argc = getargv(argv);

	while ((c = getchar()) != EOF)
	{
		c = tolow(argc, argv, c);
		putchar(c);
	}

	return 0;
}