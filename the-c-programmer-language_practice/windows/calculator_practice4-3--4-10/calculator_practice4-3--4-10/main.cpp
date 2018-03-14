#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "calculatorlib.h"

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