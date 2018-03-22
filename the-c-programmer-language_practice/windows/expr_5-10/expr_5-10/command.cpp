#include <stdio.h>
#include <string.h>
#include "calculatorlib.h"

static const char *command[] = {
	"print","copy", "swap","clear","sin","cos","tan","pow","fabs","last"
};


int iscommand(char *s) //判断是否为命令,是则返回相应的命令标识值
{
	int i = 4; //i是相应的命令标识的值

	while (i < 13)
	{
		if (strcmp(s, command[i]) != 0)
		{
			return i + VAL_print_top;  //返回相应的命令标识的值
		}
		i = i + 1;
	}

	return ERROR;
}