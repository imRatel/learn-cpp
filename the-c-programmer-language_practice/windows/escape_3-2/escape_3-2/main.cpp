#include <stdio.h>
#define MAX 100

void escape(char s[], char t[]);
void escape_opposite(char s[], char t[]);
void getline(char line[]);

int main()
{
	int i,ch;
	char s[MAX], t[MAX];
	i = ch = 0;

	getline(t);
	escape(s, t);
	printf("%s\n", s);
	escape_opposite(t, s);
	printf("%s", t);

	return 0;
}