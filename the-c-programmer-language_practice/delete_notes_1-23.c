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

//删除C语言中的注释语句,位置保持不变
int main ()
{
	int i,a,ch,state;
	char line[MAX];
	i = a = ch = state = 0;

	while ((ch = getchar()) != EOF)  //如果输入到结束符,终止循环,并输出
	{
		line[i] = ch;	//把记录字符放在最前面,因为在末尾i要加一.如果这句话在末尾,i就比最后一次记录多了一,判断就不准了.
		if (line[i] == '*' && line[i-1] == '/')
		{
			a = 2;
			state = IN;
		}
		else if (line[i] == '/' && line[i-1] == '*')
		{
			if (state == IN)
			{
				while (a > 0)
				{
					if (line[i-a+1] == '\t')		//多加1是因为,如有8个字符后4个注释,那注释就是从第5个开始计算,而8-4=4因而加1.
						line[i-a+1] = '\t';
					else
						line[i-a+1] = ' ';

					--a;
					state = OUT;
				}
			}
		}
		
		++i;
		++a;
	}

	line[i] = '\0';
	printf("%s",line);
	return 0;
}
