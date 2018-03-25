#include <stdio.h>
#include <ctype.h>

extern int free,dir;

char Atoa(char a)
{
	if (a > 'A' && a < 'Z')
	{
		return a + 'a' - 'A';
	}

	return a;
}

int strcmp(char *p1, char *p2)
{
	int n1, n2;
	int ch1, ch2;

	for (n1 = n2 = 0; (ch1 = p1[n1]) != '\0' && (ch2 = p2[n2]) != '\0'; n1++, n2++)
	{
		if (free == 1)
		{
			ch1 = Atoa(ch1);
			ch2 = Atoa(ch2);
		}

		if (dir == 1)
		{
			while (ispunct(ch1) &&  ch1 != '\0')
			{
				n1 = n1 + 1;
				ch1 = p1[n1];
			}
			while (ispunct(ch2) && ch2 != '\0')
			{
				n2 = n2 + 1;
				ch2 = p2[n2];
			}
			if (ch1 == '\0' || ch2 == '\0')
			{
				continue;
			}
		}

		if (ch1 != ch2)
		{
			return ch1 - ch2;
		}
	}

	return ch1 - ch2;
}