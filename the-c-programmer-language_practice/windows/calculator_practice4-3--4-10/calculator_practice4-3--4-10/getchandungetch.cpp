#include <stdio.h>

#define FULL 1		//��ʾ״̬��
#define EMPTY 0		//��ʾ״̬��

int next_char = EMPTY;  //��������ַ�
int s_getch = EMPTY;	//next_char��״̬

int getch()			//��ȡ�ַ�,����ϴλ�ȡʱ�ж�����ַ�,���ȷ����ϴζ����
{
	switch (s_getch)
	{
	case FULL:
		s_getch = EMPTY;
		return next_char;
		break;
	case EMPTY:
		return getchar();
		break;
	}
}

void ungetch(int ch)	//���������ַ�,����ֿ������򱨴�
{
	switch (s_getch)
	{
	case FULL:
		printf("ungetch : too many char!");
		break;
	case EMPTY:
		next_char = ch;
		s_getch = FULL;
		break;
	}
}


