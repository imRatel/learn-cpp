#include <stdio.h>
#define MAX 1000

int strrindes(char s[], char t[]);

int main()
{
	char s[MAX] = "1234512345";
	char t[MAX] = "345";
	printf("%d", strrindes(s, t));
	return 0;
}