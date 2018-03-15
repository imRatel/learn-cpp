#include <stdio.h>

void strcat(char *s1, char *s2)
{
	int n = 0;	//被赋值字符串的指针位置

	while (*(s1 + n) != '\0')	//跳过被赋值字符串的已有字符
	{
		n = n + 1;
	}

	for (int i = 0; *(s2 + i) != '\0'; i = i + 1)	//把s2中的字符赋值到s1的末尾
	{
		*(s1 + n) = *(s2 + i);
		n = n + 1;
		*(s1 + n + 1) = '\0';
	}
}