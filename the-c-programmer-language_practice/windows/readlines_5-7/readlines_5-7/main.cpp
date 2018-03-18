#include <stdio.h>

int main()
{
	char test[] = "123";

	putchar(*test + 2);
	putchar(*(test + 2));

	return 0;
}