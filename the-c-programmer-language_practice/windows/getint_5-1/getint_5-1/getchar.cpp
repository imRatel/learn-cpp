#include <stdio.h>

#define EMPTY 0
#define FULL 1

int next_char = EMPTY;  //多出来的字符
int s_getch = EMPTY;	//next_char的状态

int getch()			//获取字符,如果上次获取时有多余的字符,则先返回上次多余的
{
	if (s_getch == FULL)
	{
		s_getch = EMPTY;
		return next_char;
	}
	else
		return next_char = getchar();
}
