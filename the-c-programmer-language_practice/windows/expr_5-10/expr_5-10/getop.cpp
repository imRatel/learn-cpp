#include <stdio.h>
#include <ctype.h>
#include "calculatorlib.h"

int isnumsign(int ch)	//�ж��Ƿ�Ϊ������������(+,-,*,/,%)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 1;
	else
		return 0;
}

int  getop(char *s, char *op)	//��ȡһ��������
{
	int i, ch, nop;
	i = ch = nop = 0;

	while ((*s = ch = *(op + nop)) == ' ' || ch == '\t')	//�����ո��
	{
		nop = nop + 1;
	}

	s[1] = '\0';

	if (isnumsign(ch) || ch == '\n' || ch == EOF)	//��������Ϊ��Ч����������ʱ���ظò�����
	{
		return ch;
	}

	if (ch == '=')	//��ǰ����Ϊ�Ⱥ�ʱ,�ж��Ƿ�Ϊ��ֵ����,���Ƿ��ظ�ֵ���,���򷵻ش�����Ϣ		*sΪ�ñ���������
	{
		nop = nop + 1;
		while (isalpha(s[i++] = *(op + nop)))	//���ǵȺ�
		{
			nop = nop + 1;
		}

		if (i > 2)
		{
			printf(" \n'='so mang char for VARIABLE \n");
			return ERROR;
		}

		s[1] = '\0';
		return ASSIGNMENT;
	}

	if (isalpha(ch))	//Ϊ�����Ǽ�¼�������������
	{
		while (isalpha(s[i++] = *(op + nop)) && i < 20)
		{
			nop = nop + 1;
		}

		if (i <= 2 && isalpha(s[i - 1]))	//Ϊ�������ر������	*sΪ�ñ���������
		{
			s[1] = '\0';
			return VARIABLE;
		}

		s[i] = '\0';
		return COMMAND;
	}

	if (isdigit(ch))	//Ϊ����ʱ��¼���ֲ��������ֱ��
	{
		while (isdigit(s[i++] = *(op + nop)))
		{
			nop = nop + 1;
		}

		if (ch == '.')
		{
			while (isdigit(s[i++] = *(op + nop)))
			{
				nop = nop + 1;
			}
		}

		s[i] = '\0';
		return NUMBER;
	}

	printf("\nerror : input error!\n");
	return ERROR;
}


