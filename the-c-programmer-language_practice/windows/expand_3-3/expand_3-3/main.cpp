#include <stdio.h>
#define MAX 1000

void expand(char *s1, char *s2);
void getline(char *line);

int main()
{
	char s1[MAX], s2[MAX];

	getline(s1);
	expand(s1, s2);
	printf("String1:\n%s\n\nString2:\n%s", s1, s2);
	return 0;
}