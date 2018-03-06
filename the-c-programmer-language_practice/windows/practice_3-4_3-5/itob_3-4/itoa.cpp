#include <stdio.h>

void reverse(char s[]); 
int strlen(char s[]); 

void smover(char s[], int n)  //���ַ���������nΪ�ƶ��Ĵ���,��߿ճ������ÿո�����
{
	int now;
	now = strlen(s) + 1;

	for (int i = now + n; i > 0; --i)
	{
		if (i > n)
			s[i - 1] = s[--now];
		else
			s[i - 1] = ' ';
	}
}

void itoa(int n, char s[], int w)  //��ϰ3-4��3-6�Ľ�ϰ�
{
	int i,sign;
	unsigned n_c;
	n_c = i = sign = 0;

	if (n < 0)           //�ж��������Ƿ�Ϊ��С����
	{
		if (n - 1 > 0)
		{
			n_c = n;
		}
		else
			n_c = -n;
	}
	else
		n_c = n;

	do                   //������ת��Ϊ�ַ�����ʽ,������˳���Ƿ���
	{
		s[i++] = n_c % 10 + '0';
		n_c /= 10;
		++sign;
	} while (n_c > 0);

	if (n < 0)
	s[i++] = '-';

	s[i] = '\0';
	reverse(s);  //�����ַ�ת

	if (sign < w)  //�ж��Ƿ�С���趨���
		smover(s, w - sign);

}