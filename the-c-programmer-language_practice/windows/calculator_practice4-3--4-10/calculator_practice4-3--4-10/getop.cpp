#include <stdio.h>
#include <ctype.h>

#define MAXLAN 100	//操作符最大长度
#define NUMBER '0'	//标记为数字
#define COMMAND 1	//标记为命令
#define ERROR 2		//标记为错误
#define ASSIGNMENT 3//标记为赋值
#define VARIABLE 'a'//标记为变量

int getch();
void ungetch(int ch);

int isnumsign(int ch)	//判断是否为算数操作符号(+,-,*,/,%)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 1;
	else
		return 0;
}

int  getop(char s[])	//获取一个操作符
{
	int i, ch;
	i = ch = 0;

	while ((s[0] = ch = getch()) == ' ' || ch == '\t')	//跳过空格符
		;
	
	s[1] = '\0';
	
	if (isnumsign(ch) || ch == '\n' || ch == EOF)	//当操作符为有效单个操作符时返回该操作符
	{
			return ch;
	}
	
	if (ch == '=')	//当前符号为等号时,判断是否为赋值运算,如是返回赋值标记,否则返回错误信息		s[0]为该变量的名字
	{
		while (isalpha(s[i++] = ch = getch()))	//覆盖等号
			;

		if (i > 2)
		{
			printf(" \n'='so mang char for VARIABLE \n");
			return ERROR;
		}

		s[1] = '\0';
		ungetch(ch);
		return ASSIGNMENT;
	}

	if (isalpha(ch))	//为命令是记录命令并返回命令标记
	{
		while (isalpha(s[++i] = ch = getch()))
			;

		if (i <= 2 && isalpha(s[i-1]))	//为变量返回变量标记	s[0]为该变量的名字
		{
			s[1] = '\0';
			ungetch(ch);
			return VARIABLE;
		}

		s[i] = '\0';
		ungetch(ch);
		return COMMAND;
	}

	if (isdigit(ch))	//为数字时记录数字并返回数字标记
	{
		while (isdigit(s[++i] = ch = getch()))
			;

		if (ch == '.')
			while (isdigit(s[++i] = ch = getch()));

		s[i] = '\0';
		ungetch(ch);
		return NUMBER;
	}

	printf("\nerror : input error!\n");
	return ERROR;
}