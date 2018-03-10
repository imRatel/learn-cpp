#include <stdio.h>

#define MAXVAL 100

int n_val = 0; //堆栈当前数目
double val[MAXVAL]; //堆栈,最大数目为100

void push(double f) //把当前数字压入堆栈,如果溢出,返回错误信息
{
	if (n_val < MAXVAL)
	{
		val[n_val++] = f;
	}
	else
		printf("\nerror:The val is already full!\n");
}

double pop() //取出堆栈最上面的数字,当堆栈空时返回0.0,并警告提示
{
	if (n_val > 0)
	{
		return val[--n_val];
	}
	else
	{
		printf("\nwaring:The val is empy!");
		return 0.0;
	}
}