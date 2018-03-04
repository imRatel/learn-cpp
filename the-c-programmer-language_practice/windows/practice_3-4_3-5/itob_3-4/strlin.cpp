#include <stdio.h>

int strlen(char s[]) //判断字符串长度 不计算\0
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i - 1;
}