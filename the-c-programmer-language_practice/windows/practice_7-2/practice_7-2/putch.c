#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define OCT 8
#define HEX 16
 
int getch();
int  ungetch(int ch);

int isoct(char c)
{
	return (c >= '1' && c <= '8');
}

int ishex(char c)
{
	return (c >= '1' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F');
}

int putch()
{
	int c,i = 0;
	char num[MAX];
	if ((c = getch()) == '0')
	{
		num[i] = c;
		i++;
		if ((c = getch()) == 'x' || c == 'x')			//���Ϊ16�������
		{
			num[i] = c;
			i++;

			while (ishex(c = getch()))					//��¼��������16�����ַ�
			{
				num[i] = c;
				i++;
			}
			ungetch(c);
			num[i] = '\0';
			if (i > 2)									//��ȷʵΪʮ���������֣�����ת������������
			{
				c = (int)strtol(num, NULL, HEX);
				return c;
			}
			while (i > 0)								//����ʮ�����ƣ�ѹ�ؼ�¼���ַ�
			{
				i--;
				ungetch(num[i]);
			}
			c = getch();								//Ϊ����ֵ��ȡһ���ַ�
		}
		else
		{
			while (isoct(c = getch()))
			{
				num[i] = c;
				i++;
			}
			ungetch(c);
			num[i] = '\0';
			if (i > 1)
			{
				c = (int)strtol(num, NULL, OCT);
				return c;
			}
			ungetch('0');
			c = getch();
		}
	}

	return c;
}