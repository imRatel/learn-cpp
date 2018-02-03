/*************************************************************************
    > File Name: entab_1-21_others.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 01 Feb 2018 10:55:31 AM DST
 ************************************************************************/

#include<stdio.h>
#define MAX 1000
#define wide 144
#define w_t 8
#define N 24

int main ()
{
	int a,n_s,n_t,n_ch,i,ch;
	char line[MAX];
	a = n_s = n_t = n_ch = i = ch = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			++n_s;
			
			if (n_s + n_ch == w_t)
			{
				n_s = 0;
				if (N > a)
				{
					n_t = (N-a)/w_t+1;
				}
				else
				{
					n_t = N/w_t;
					line[i] = '\t';
					++i;
					line[i] = '\n';
					++i;
				}
				n_ch = 0;
				a = N;

				while (n_t > 0)
				{
					line[i] = '\t';
					--n_t;
					++i;
				}
			}
		}
		else
		{
			while (n_s > 0)
			{
				line[i] = ' ';
				++i;
				--n_s;
				++a;
				++n_ch;
			}

			line[i] = ch;
			++i;
			++n_ch;
			++a;
			
			if (ch == '\n')
			{
				a = 0;
				n_ch = 0;
			}
			else if (n_ch == w_t)
				n_ch = 0;
		}
	}
	line[i] = '\0';
	printf("%s",line);
	return 0;
}
