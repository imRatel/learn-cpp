#include <stdio.h>

void reverse(char *s);

void itob(int n, char *s, int b) //根据需要的底数把整形数转换为相应进制的字符串形式
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