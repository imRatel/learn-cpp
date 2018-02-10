/*************************************************************************
    > File Name: error-back_1-24.c
    > Author: ratel
    > Mail: 920796548@qq.com 
    > Created Time: 2018年02月06日 星期二 21时40分55秒
 ************************************************************************/

#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX 1000
#define brace 1 //大括号
#define bracket 2 //中括号
#define parenthesis 3 //小括号
#define d_quote 4 //双引号
#define s_quote 5 //单引号
#define notes 6 //注释符号
#define ASC 7 //ASC转义符号
int control[MAX],error_line[MAX]; 
char error[MAX][MAX];
int n_l,n_e;
int a,i,x;
int d_s,s_s;	//d_s为double state双引号状态,s_s为single state单引号状态

void back_error ()
{
	error_line[x] = n_l;
	++x;
	if (control[a-1] == brace)
	{
		error[n_e] = "error:brace";
	}
	else if (control[a-1] == bracket)
	{
		error[n_e] = "error:bracket";
	}
	else if (control[a-1] == parenthesis)
	{
		error[n_e] = "error:parenthesis";
	}
	else if (control[a-1] == d_quote)
	{
		error[n_e] = "error:double quote";
	}
	else if (control[a-1] == s_quote)
	{
		error[n_e] = "error:single quote";
	}
	else if (control[a-1] == notes)
	{
		error[n_e] = "error:notes";
	}
	--a;
}

void judge_ASC (char now)
{

}

void choose_state (char line[])
{
	if (line[i] == '{')
		control[a] = brace, ++a;
	else if (line[i] == '[')
		control[a] = bracket, ++a;
	else if (line[i] == '(')
		control[a] = parenthesis, ++a;
	else if (line[i] == '*' && line[i-1] == '/')
		control[a] = notes, ++a;
}

void judge_state (char line[])
{
	if (line[i] == '}')
	{
		if (control[a-1] == brace)
			--a;
		else
			back_error();
	}
	else if (line[i] == ']')
	{
		if (control[a-1] == bracket)
			--a;
		else
			back_error();
	}
	else if (line[i] == ')')
	{
		if (control[a-1] == parenthesis)
			--a;
		else
			back_error();
	}
	else if (line[i] == '/' && line[i-1] == '*')
	{
		if (control[a-1] == notes)
			--a;
		else
			back_error();
	}
}

int main ()
{
	int ch;
	char line[MAX];
	d_s = s_s = OUT;
	ch = i = a = x = n_l = n_e = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\t')
		{
			++n_l;
		}
		line[i] = ch;
		if (ch == '\"'&& d_s == OUT)
		{
			d_s = IN;
		}
		else if(ch == '\'' && s_s ==OUT)
		{
			s_s = IN;
		}
		else if (d_s == IN || s_s == IN)
		{
			if (line[i-1] == '\\')
				judge_ASC(line[i]);
			else if (ch == '\"')
			{
				d_s = OUT;
			}
			else if(ch == '\'')
			{
				s_s = OUT;
			}
		}
		else 
		{
			choose_state(line);
			judge_state(line);
		}
	}
	back_error();
	line[i] = '\0';
	prentf("%s\n%s%d",line,error,error_line);
	return 0;
}
