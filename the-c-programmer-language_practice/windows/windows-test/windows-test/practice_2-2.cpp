#include <stdio.h>
#define MAX 1000

int main()
{
	int i,ch;
	int line[MAX];
	for (i = 0; i < MAX - 1 && (ch = getchar()) != '`' && ch != '\n'; ++i)
		line[i] = ch;
	for (i = 0; !((i < MAX - 1) + ((ch = getchar()) != '`') + (ch != '\n')); ++i)
		line[i] = ch;
	return 0;
}