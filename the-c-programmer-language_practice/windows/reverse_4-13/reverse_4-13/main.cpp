#include <stdio.h>
#include <string>

void reverse(char s[], int low, int high);

int main()
{
	int low, high;
	char s[100] = "123456";

	low = 0;
	high = strlen(s) - 1;

	reverse(s, low, high);
	printf("%s", s);
	return 0;
}