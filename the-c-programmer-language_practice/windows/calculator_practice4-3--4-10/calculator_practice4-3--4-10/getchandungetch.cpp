#include <stdio.h>

#define FULL 1		//��ʾ״̬��
#define EMPTY 0		//��ʾ״̬��

int next_char = EMPTY;  //��������ַ�
int s_getch = EMPTY;	//next_char��״̬

int getch()			//��ȡ�ַ�,����ϴλ�ȡʱ�ж�����ַ�,���ȷ����ϴζ����
{
	if (s_getch == FULL)
	{
		s_getch = EMPTY;
		return next_char;
	} 
	else
		return getchar();
}

void ungetch(int ch)	//���������ַ�,����ֿ������򱨴�
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
}


