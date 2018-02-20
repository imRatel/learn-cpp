#include <stdio.h>
#define MAX 1000

void squeeze(char s1[], char s2[])
{
	int n_1, n_2, n_3, n_c, control;
	char s3[MAX];
	n_1 = n_2 = n_3 = n_c = control = 0;
	while (s1[n_1] != '\0')
	{
		if (s1[n_1] == s2[n_2])
		{
			++n_2;
		}
		else if (s2[n_2] == '\0')
		{
			n_3 = n_3 - n_2;
			n_2 = 0;
		}
		else
		{
			n_2 = 0;
		}

		s3[n_3] = s1[n_1];
		++n_1, ++n_3;
	}

	s3[n_3] = '\0';
	while (n_3 >= 0)
	{
		s1[n_3] = s3[n_3];
		--n_3;
	}
}