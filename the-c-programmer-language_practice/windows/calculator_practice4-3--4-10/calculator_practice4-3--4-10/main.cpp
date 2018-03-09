#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 //操作数或运算反应的最大长度
#define MAXLAN 100	//操作符最大长度
#define NUMBER '0'	//标记为数字
#define COMMAND 1	//标记为命令
#define ERROR 2		//标记为错误
#define ASSIGNMENT 3//标记为赋值

#define VAL_print_top 4		//打印最上层值
#define VAL_copy_top 5		//复制最上层值
#define VAL_swap_top 6		//交换最上面两个数的值
#define VAL_clear 7			//清空堆栈

int  getop(char s[]);	//获取操作符
void push(double f);	//把当前数字压入堆栈
double pop();			//提取一个堆栈值

int main()	//逆波兰计算器
{
	//需要自己写一个判断是什么命令的函数
	//并且需要在原基础上添加分支,赋值运算分支,命令分支,变量分支,错误分支
}