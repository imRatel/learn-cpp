#include <stdio.h>
#include "calculatorlib.h"

int next_char = EMPTY;  //��������ַ�
int s_getch = EMPTY;	//next_char��״̬

extern int n_line;//��������еļ���(main)

int getch(char line[])			//��ȡ�ַ�,����ϴλ�ȡʱ�ж�����ַ�,���ȷ����ϴζ����
{
	if (s_getch == FULL)
	{
		s_getch = EMPTY;
		return next_char;
	} 
	else
		return line[n_line++];
}

/*void ungetch(int ch)	//���������ַ�,����ֿ������򱨴�
{
	switch (s_getch)
	{
	case FULL:
		printf("\nungetch : too many char!\n");
		break;
	case EMPTY:
		next_char = ch;
		s_getch = FULL;
		break;
	}
}*/


