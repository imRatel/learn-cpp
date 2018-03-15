#include <stdio.h>

int strend(char *s1, char *s2);

int main()
{
	char s1[] = "12345";
	char s2[] = "5";

	if (strend(s1, s2))
	{
		 printf("yes");
	}
	return 0;
}