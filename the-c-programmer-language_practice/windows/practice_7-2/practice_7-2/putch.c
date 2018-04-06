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
		if ((c = getch()) == 'x' || c == 'x')			//如果为16进制情况
		{
			num[i] = c;
			i++;

			while (ishex(c = getch()))					//记录后面所有16进制字符
			{
				num[i] = c;
				i++;
			}
			ungetch(c);
			num[i] = '\0';
			if (i > 2)									//当确实为十六进制数字，进行转换操作并返回
			{
				c = (int)strtol(num, NULL, HEX);
				return c;
			}
			while (i > 0)								//不是十六进制，压回记录的字符
			{
				i--;
				ungetch(num[i]);
			}
			c = getch();								//为返回值获取一个字符
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