#include <stdio.h>
#define MAX 1000

void squeeze(char s1[], char s2[]);
void getline(char line[]);

int main()
{
	char s1[MAX], s2[MAX];
	getline(s1);
	getline(s2);
	squeeze(s1, s2);
	printf("%s", s1);
	getchar();
	return 0;
}

void getline(char line[])
{
	int i, ch;
	i = ch = 0;
	while ((ch = getchar()) != '\n')
	{
		line[i] = ch;
		++i;
	}

	line[i] = '\0';
}

void squeeze(char s1[], char s2[])
{
	int n_1, n_2, n_3, n_c,control;
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