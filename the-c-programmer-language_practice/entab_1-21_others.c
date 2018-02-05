/*************************************************************************
    > File Name: entab_1-21_others.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 01 Feb 2018 10:55:31 AM DST
 ************************************************************************/

#include<stdio.h>
#define MAX 1000	//最大输入
#define wide 144	//页面宽度
#define w_t 8		//制表符宽度
#define N 24		//终止位
#define IN 1
#define OUT 0

//把空格换成最少数量的制表符和空格,使制表符和空格充满到下一个制表符终止位的地方.
int main ()
{
	int a,n_s,n_t,n_ch,i,ch,state;
	char line[MAX];
	a = n_s = n_t = n_ch = i = ch = state = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			if (state == OUT)
			++n_s;
			
			if (n_s + n_ch == w_t && state == OUT)
			{
				state = IN;
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
					n_s = 0;
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
			
			state = OUT;
			line[i] = ch;
			++i;
			++n_ch;
			++a;
			if (ch == '\t')
				a += 3;
			
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
