#include <stdio.h>
#include <ctype.h>
#include "calculatorlib.h"

int isnumsign(int ch)	//判断是否为算数操作符号(+,-,*,/,%)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 1;
	else
		return 0;
}

int  getop(char *s, char *op)	//获取一个操作符
{
	int i, ch, nop;
	i = ch = nop = 0;

	while ((*s = ch = *(op + nop)) == ' ' || ch == '\t')	//跳过空格符
	{
		nop = nop + 1;
	}

	s[1] = '\0';

	if (isnumsign(ch) || ch == '\n' || ch == EOF)	//当操作符为有效单个操作符时返回该操作符
	{
		return ch;
	}

	if (ch == '=')	//当前符号为等号时,判断是否为赋值运算,如是返回赋值标记,否则返回错误信息		*s为该变量的名字
	{
		nop = nop + 1;
		while (isalpha(s[i++] = *(op + nop)))	//覆盖等号
		{
			nop = nop + 1;
		}

		if (i > 2)
		{
			printf(" \n'='so mang char for VARIABLE \n");
			return ERROR;
		}

		s[1] = '\0';
		return ASSIGNMENT;
	}

	if (isalpha(ch))	//为命令是记录命令并返回命令标记
	{
		while (isalpha(s[i++] = *(op + nop)) && i < 20)
		{
			nop = nop + 1;
		}

		if (i <= 2 && isalpha(s[i - 1]))	//为变量返回变量标记	*s为该变量的名字
		{
			s[1] = '\0';
			return VARIABLE;
		}

		s[i] = '\0';
		return COMMAND;
	}

	if (isdigit(ch))	//为数字时记录数字并返回数字标记
	{
		while (isdigit(s[i++] = *(op + nop)))
		{
			nop = nop + 1;
		}

		if (ch == '.')
		{
			while (isdigit(s[i++] = *(op + nop)))
			{
				nop = nop + 1;
			}
		}

		s[i] = '\0';
		return NUMBER;
	}

	printf("\nerror : input error!\n");
	return ERROR;
}


