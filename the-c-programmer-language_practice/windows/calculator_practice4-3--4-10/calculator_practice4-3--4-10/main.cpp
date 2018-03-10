#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 //操作数或运算反应的最大长度
#define MAXVAL 100	//堆栈最大数量
#define VARIABLE 'a'//标记为变量
#define NUMBER '0'	//标记为数字
#define COMMAND 1	//标记为命令
#define ERROR 2		//标记为错误
#define ASSIGNMENT 3//标记为赋值


#define VAL_print_top 4		//打印最上层值
#define VAL_copy_top 5		//复制最上层值
#define VAL_swap_top 6		//交换最上面两个数的值
#define VAL_clear 7			//清空堆栈
#define SIN 8				//正弦函数
#define COS 9				//余弦函数
#define TAN 10				//正切函数
#define POW 11				//次方函数
#define FABS 12				//绝对值函数

int  getop(char s[],char line[]);	//获取操作符
void push(double f);	//把当前数字压入堆栈
double pop();			//提取一个堆栈值
int iscommand(char s[]);//判断是什么命令
int linecmp(char s1[], char s2[]);	//判断两个字符串是否相等		!!注意!!此函数跳过字符串开头的非字母字符
void getline(char line[]);	//获取一个行

int n_line = 0;			//最大输入行的计数

int main()	//逆波兰计算器
{
	int type;	//储存相对应的操作类型
	double op2,op3;	//临时存放操作
	char s[MAXOP];			//储存输入的操作
	double var[MAXOP + 'z'];	//储存变量
	double last = 0.0;			//上一次打印的值
	char line[MAXOP];		//最大输入行
	
	getline(line);

	while ((type = getop(s,line)) != EOF)
	{
		switch (type)
		{
		case NUMBER:	//为数字,压入堆栈
			push(atof(s));
			break;
		case '+':		//为加法
			push(pop() + pop());
			break;
		case '*':		//为乘法
			push(pop() * pop());
			break;
		case '-':		//为减法
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':		//为除法
			op2 = pop();
			push(pop() / op2);
			break;
		case '%':		//为求余
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case '\n':		//打印最运算值,并储存
			last = pop();
			printf("end\t=%.8g\n",last);
			break;

		case COMMAND:	//为命令符
			switch (iscommand(s))
			{
			case VAL_print_top:	
				printf("\nVAL top = %.8g\n", last = op2 = pop());
				push(op2);
				break;
			case VAL_copy_top:
				push(op2 = pop());
				push(op2);
				break;
			case VAL_swap_top:
				op2 = pop();
				op3 = pop();
				push(op3);
				push(op2);
				break;
			case VAL_clear:
				for (int i = 0; i < MAXVAL; i++)
					pop();
				break;
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				push(tan(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case FABS:
				push(fabs(pop()));
				break;
			case ERROR:
				printf("\nnot found this older\n");
				break;
			}
			break;

		case ASSIGNMENT:	//为赋值
			var['z' - s[0]] = pop();
			break;
		case VARIABLE:		//为变量
			push(var['z' - s[0]]);
			break;

		case ERROR:
			printf("\nnot found this older\n");
			break;
		}
	}

	return 0;
}