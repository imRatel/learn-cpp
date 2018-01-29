#include <stdio.h>
#define n 20
#define wide 100
#define MAX 10000

int main ()
{
	int a,ch,i,x;
	char line[MAX];
	a = ch = i = x = 0;

	while ((ch=getchar()) != EOF)
	{
		if (ch == '\n')
		{
			a = 0;
			line[i]=ch;
			++i;
		}
		else if (ch == '\t')
		{
			if (n > a)
				for (;n > a;++a,++i)
					line[i] = ' ';
			else 
			{
				for (x = wide - a + n; x > a;++i,++a)
					line[i] = ' ';

				a = n;
			}
		}
		else
		{
			line[i] = ch;
			++i;
		}
	}

	line[i] = '\0';
	printf("%s",line);

	return 0;
}
