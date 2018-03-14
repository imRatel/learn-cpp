#include <stdio.h>
#include "calculatorlib.h"

int next_char = EMPTY;  //多出来的字符
int s_getch = EMPTY;	//next_char的状态

extern int n_line;//最大输入行的计数(main)

int getch(char line[])			//获取字符,如果上次获取时有多余的字符,则先返回上次多余的
{
	if (s_getch == FULL)
	{
		s_getch = EMPTY;
		return next_char;
	} 
	else
		return line[n_line++];
}

/*void ungetch(int ch)	//储存多余的字符,如果仓库已满则报错
{
	switch (s_getch)
	{
	case FULL:
		printf("\nungetch : too many char!\n");
		break;
	case EMPTY:
		next_char = ch;
		s_getch = FULL;
		break;
	}
}*/


