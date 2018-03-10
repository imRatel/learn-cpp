#include <stdio.h>
#include <string.h>

#define MAXLIB 100
#define ERROR 2
#define VAL_print_top 4		//打印最上层值
#define VAL_copy_top 5		//复制最上层值
#define VAL_swap_top 6		//交换最上面两个数的值
#define VAL_clear 7			//清空堆栈
#define SIN 8				//正弦函数
#define COS 9				//余弦函数
#define TAN 10				//正切函数
#define POW 11				//次方函数
#define FABS 12				//绝对值函数

int linecmp(char s1[], char s2[]);//判断两个字符串是否相等		!!注意!!此函数跳过字符串开头的非字母字符

char command[MAXLIB][MAXLIB];	//命令所对应的字符串的储存数组

void commandlib ()	//储存所有命令相应字符串的函数
{
	strcpy_s(command[4], "print");
	strcpy_s(command[5], "copy");
	strcpy_s(command[6], "swap");
	strcpy_s(command[7], "clear");
	strcpy_s(command[8], "sin");
	strcpy_s(command[9], "cos");
	strcpy_s(command[10], "tan");
	strcpy_s(command[11], "pow");
	strcpy_s(command[12], "fabs");
}

int iscommand(char s[]) //判断是否为命令,是则返回相应的命令标识值
{
	int i = 4; //i是相应的命令标识的值

	commandlib();

	while (i < 13)
	{
		if (linecmp(s, command[i++]))
			return --i;   //返回相应的命令标识的值
	}

	return ERROR;
}