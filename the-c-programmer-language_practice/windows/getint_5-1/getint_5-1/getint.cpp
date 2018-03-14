#include <stdio.h>
#include <ctype.h>

#define EMPTY 0
#define FULL 1

int getch();
extern int s_getch;	//next_char��״̬

double getint(double *num)
{
	int sign = 1;
	int ch;
	double pow;

	while (isspace(ch = getch()))	//�����հ�
		;

	if (!isdigit(ch) && ch != EOF && ch != '-' && ch != '+')	//�жϷ���
	{
		s_getch = FULL;
		return 0;
	}

	sign = (ch == '-') ? -1 : 1;	//��Ƿ���
	if (ch == '+' || ch == '-')
	{
		while (isspace(ch = getch()))	//�������ź���Ŀհ�
			;
	}

	for (*num = 0; isdigit(ch); ch = getch())	//��¼��������
	{
		*num = 10.0 * *num + (ch - '0');
	}

	if (ch = '.')
		ch = getch();
	
	for (pow = 1.0; isdigit(ch); ch = getch())	//��¼С������
	{
		*num = 10.0 * *num + (ch - '0');
		pow *= 10.0;
	}

	*num = sign * *num / pow;
	if (ch != EOF)
		s_getch = FULL;

	return ch;

}