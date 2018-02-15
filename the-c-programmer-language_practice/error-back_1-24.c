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
#define notes 6 //注释
#define ASC 7 //ASC转义符号
int control,error_line[MAX]; //control储存输入的符号信息,error_line[]记录错误行号 
const char *error[MAX]; //储存错误信息
int n_l,n_e; //n_l为行号记录的变量,n_e为记录错误信息error的控制变量
int a,i,x;  //a为输入文本中的记录括号control的控制变量,i为记录输入字符line的控制变量
			//x为记录错误信息行号error_line的控制变量
int d_s,s_s;	//d_s为double state双引号状态,s_s为single state单引号状态

/*先记录当前行号,利用control记录的符号信息,判断错误的符号信息,a-1是最近一次输入的左半边字符*/
void back_error ()
{

	printf("back");
	error_line[n_e] = n_l;

	if (control%10 == brace)
	{
		error[n_e] = "error:brace\n";
	}
	else if (control%10 == bracket)
	{
		error[n_e] = "error:bracket\n";
	}
	else if (control%10 == parenthesis)
	{
		error[n_e] = "error:parenthesis\n";
	}
	else if (control%10 == d_quote)
	{
		error[n_e] = "error:double quote\n";
	}
	else if (control%10 == s_quote)
	{
		error[n_e] = "error:single quote\n";
	}
	else if (control%10 == notes)
	{
		error[n_e] = "error:notes\n";
	}
	control /= 10;
	++n_e;
}

/*判断右斜杠后的字符是否为正确的ASC字符,不是记录错误信息*/
void judge_ASC (char now)
{
	if (now != 'n' || now != 'b' || now != 'r' || now != 'f' || now != 't' || now != '\\' || now != '\?' || now != '\'' || now != '\"' || now != 'v' || now != 'a')
	{
		error_line[n_e] == n_l;
		error[n_e] = "error:ASCII\n";
		++n_e;
	}
}

/*当判断输入为左半边符号时,用control记录符号信息*/
void choose_state (char line[])
{

	printf("choose");
	if (line[i] == '{')
		control = brace + control * 10;
	else if (line[i] == '[')
		control = bracket + control * 10;
	else if (line[i] == '(')
		control = parenthesis + control * 10;
	else if (line[i] == '*' && line[i-1] == '/')
		control = notes + control * 10;
}

/*当输入字符为右半边符号时,判断是否与最近一次输入的左半边类型相同,不相同进入back_error判断错误信息*/
void judge_state (char line[])
{
	printf("judge");
	if (line[i] == '}')
	{
		if (control%10 == brace)
			control/=10;
		else
			back_error();
	}
	else if (line[i] == ']')
	{
		if (control%10 == bracket)
			control/=10;
		else
			back_error();
	}
	else if (line[i] == ')')
	{
		if (control%10 == parenthesis)
			control/=10;
		else
			back_error();
	}
	else if (line[i] == '/' && line[i-1] == '*')
	{
		if (control%10 == notes)
			control/=10;
		else
			back_error();
	}
}

/*输入字符并记录到line[],判断为回车行号增加n_l,判断为左单引号双引号,记录状态为IN,直到输入为右引号状态为OUT,在IN中判断ASC符号是否正确,状态为OUT判断输入字符是否为右符号并判断是否出错*/
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
		else if(ch == '\'' && s_s == OUT)
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
		++i;
	}

	if (d_s == IN || s_s == IN)
	{
		error_line[n_e] == n_l;
		error[n_e] = "error:double or single\n";
		++n_e;
	}

	line[i] = '\0';
	printf("%d",n_e);
	printf("%s",error[0]);
	while (n_e < 0)
	{
		puts(error[n_e]);
		printf("error number : %d\n",error_line[n_e]);
		--n_e;
	}
	return 0;
}
