#include <stdio.h>

void reverse(char *s);

void itob(int n, char *s, int b) //������Ҫ�ĵ�����������ת��Ϊ��Ӧ���Ƶ��ַ�����ʽ
{
	int i = 0;

	do
	{
		*(s + i) = n % b + '0';
		i = i + 1;
		n /= b;
	} while (n > 0);
	*(s + i) = '\0';
	reverse(s);
}