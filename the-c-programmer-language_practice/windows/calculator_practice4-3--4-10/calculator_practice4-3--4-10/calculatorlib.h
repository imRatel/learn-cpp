#pragma once
#define MAXOP 100 //操作数或运算反应的最大长度
#define MAXVAL 100	//堆栈最大数量
#define VARIABLE 'a'//标记为变量
#define NUMBER '0'	//标记为数字
#define COMMAND 1	//标记为命令
#define ERROR 2		//标记为错误
#define ASSIGNMENT 3//标记为赋值

#define FULL 'F'		//表示状态满
#define EMPTY 'E'		//表示状态空

#define VAL_print_top 4		//打印最上层值
#define VAL_copy_top 5		//复制最上层值
#define VAL_swap_top 6		//交换最上面两个数的值
#define VAL_clear 7			//清空堆栈
#define SIN 8				//正弦函数
#define COS 9				//余弦函数
#define TAN 10				//正切函数
#define POW 11				//次方函数
#define FABS 12				//绝对值函数

int  getop(char s[], char line[]);	//获取操作符
void push(double f);	//把当前数字压入堆栈
double pop();			//提取一个堆栈值
int iscommand(char s[]);//判断是什么命令
int linecmp(char s1[], char s2[]);	//判断两个字符串是否相等		!!注意!!此函数跳过字符串开头的非字母字符
void getline(char line[]);	//获取一个行
