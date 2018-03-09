#include <stdio.h>

#define FULL 1		//表示状态满
#define EMPTY 0		//表示状态空

int next_char = EMPTY;  //多出来的字符
int s_getch = EMPTY;	//next_char的状态

int getch()			//获取字符,如果上次获取时有多余的字符,则先返回上次多余的
{
	switch (s_getch)
	{
	case FULL:
		s_getch = EMPTY;
		return next_char;
		break;
	case EMPTY:
		return getchar();
		break;
	}
}

void ungetch(int ch)	//储存多余的字符,如果仓库已满则报错
{
	switch (s_getch)
	{
	case FULL:
		printf("ungetch : too many char!");
		break;
	case EMPTY:
		next_char = ch;
		s_getch = FULL;
		break;
	}
}


