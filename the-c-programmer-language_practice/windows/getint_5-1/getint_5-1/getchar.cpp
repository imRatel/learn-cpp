#include <stdio.h>

#define EMPTY 0
#define FULL 1

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
		return next_char = getchar();
}
