#include <stdio.h>
#include <string.h>
#include "calculatorlib.h"

static const char *command[] = {
	"print","copy", "swap","clear","sin","cos","tan","pow","fabs","last"
};


int iscommand(char *s) //�ж��Ƿ�Ϊ����,���򷵻���Ӧ�������ʶֵ
{
	int i = 4; //i����Ӧ�������ʶ��ֵ

	while (i < 13)
	{
		if (strcmp(s, command[i]) != 0)
		{
			return i + VAL_print_top;  //������Ӧ�������ʶ��ֵ
		}
		i = i + 1;
	}

	return ERROR;
}