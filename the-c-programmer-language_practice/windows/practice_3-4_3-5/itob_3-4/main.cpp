#include <stdio.h>
#define MAX 1000

void itob(int n, char s[], int b);
void itoa(int n, char s[], int w);
int strlen(char s[]);
void reverse(char s[]);

int main()
{
	int n, b, ch;
	char s[MAX] = "12345";
	n = b = ch = 0;
	
	do
	{
		itoa(12345, s, 10);
		printf("%s\n", s);

		itob(12345, s, 10);
		printf("%s\n", s);

		ch = getchar();
	} while (ch != '`');
	return 0;
}