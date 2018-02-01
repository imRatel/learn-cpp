#include <stdio.h>
#define MAX 1000
#define w_t 7
#define n 21
#define wide 120

int main ()
{
	int n_t,n_s,i,a,ch;
	char line[MAX];
	n_t = n_s = i = a = ch = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			++n_s;
			
			if (n_s == w_t)
			{
				line[i] = '\t';
				n_s = 0;
				++i;
			}
		}
		else
		{
			for (;n_s > 0;--n_s)
			{
				line[i] = ' ';
				++i;
			}

			line[i] = ch;
			++i;
		}
	}
	line[i] = '\0';
	printf("%s",line);

	return 0;
}
