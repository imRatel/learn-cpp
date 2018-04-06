#include <stdio.h>
#include <string.h>


int tolow(int argc, char *argv[], char c)
{
	if (strcmp(argv[0], "tolower") == 0)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = c + 'a' - 'A';
		}
	}
	else if (strcmp(argv[0],"touper") == 0)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = c -( 'a' - 'A');
		}
	}

	return c;
}