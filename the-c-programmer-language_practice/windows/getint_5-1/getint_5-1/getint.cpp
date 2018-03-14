#include <stdio.h>
#include <ctype.h>

#define EMPTY 0
#define FULL 1

int getch();
extern int s_getch;	//next_char的状态

double getint(double *num)
{
	int sign = 1;
	int ch;
	double pow;

	while (isspace(ch = getch()))	//跳过空白
		;

	if (!isdigit(ch) && ch != EOF && ch != '-' && ch != '+')	//判断符号
	{
		s_getch = FULL;
		return 0;
	}

	sign = (ch == '-') ? -1 : 1;	//标记符号
	if (ch == '+' || ch == '-')
	{
		while (isspace(ch = getch()))	//跳过符号后面的空白
			;
	}

	for (*num = 0; isdigit(ch); ch = getch())	//记录整数部分
	{
		*num = 10.0 * *num + (ch - '0');
	}

	if (ch = '.')
		ch = getch();
	
	for (pow = 1.0; isdigit(ch); ch = getch())	//记录小数部分
	{
		*num = 10.0 * *num + (ch - '0');
		pow *= 10.0;
	}

	*num = sign * *num / pow;
	if (ch != EOF)
		s_getch = FULL;

	return ch;

}