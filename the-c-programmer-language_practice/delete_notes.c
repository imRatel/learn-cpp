/*************************************************************************
    > File Name: delete_notes.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 05 Feb 2018 04:51:57 PM DST
 ************************************************************************/

#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX 1000

int main ()
{
	int i,a,ch,state;
	char line[MAX];
	i = a = ch = state = 0;

	while ((ch = getchar()) != EOF)
	{
		if (line[i] == '*' && line[i-1] == '/')
		{
			a = 2;
			state = IN;
		}
		else if (line[i] == '/' && line[i] == '*')
		{
			if (state == IN)
			{
				while (i - a >= 0)
				{
					if (line[i-a] == '\t')

				}
			}
		}
	}
}
