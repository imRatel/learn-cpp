#include <stdio.h>

void reverse(char s[]); 
int strlen(char s[]); 

void smover(char s[], int n)  //把字符串向右移n为移动的次数,左边空出来的用空格填满
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

void itoa(int n, char s[], int w)  //练习3-4和3-6的结合版
{
	int i,sign;
	unsigned n_c;
	n_c = i = sign = 0;

	if (n < 0)           //判断正负和是否为最小负数
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

	do                   //把数字转换为字符串形式,与数字顺序是反的
	{
		s[i++] = n_c % 10 + '0';
		n_c /= 10;
		++sign;
	} while (n_c > 0);

	if (n < 0)
	s[i++] = '-';

	s[i] = '\0';
	reverse(s);  //把数字反转

	if (sign < w)  //判断是否小于设定宽度
		smover(s, w - sign);

}