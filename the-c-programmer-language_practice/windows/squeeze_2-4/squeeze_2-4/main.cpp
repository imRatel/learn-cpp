#include <stdio.h>
#define MAX 1000

void squeeze(char s1[], char s2[]);
void getline(char line[]);
int any(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	getline(s1);
	getline(s2);
	printf("%d\n", any(s1, s2));
	squeeze(s1, s2);
	printf("%s", s1);
	getchar();
	return 0;
}