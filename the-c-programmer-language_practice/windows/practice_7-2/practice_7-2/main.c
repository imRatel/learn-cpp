#include <stdio.h>

int putch();

int main()
{
	int ch;
	int i = 0;
	while ((ch = putch()) != EOF)
	{
		if (i > 10 || ch =='\n')
		{
			i = 0;
			if (ch != '\n')
			{
				putchar('\n');
			}
		}
		printf("%c", ch);
		i++;
	}
	return 0;
}