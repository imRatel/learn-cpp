#include <stdio.h>
#include <ctype.h>

#define MAXLAN 100	//操作符最大长度

int linecmp(char s1[],char s2[])//判断两个字符串是否相等		!!注意!!此函数跳过字符串开头的非字母字符
{
	int i1, i2;
	i1 = i2 = 0;

	while (!isalpha(s1[i1++]) && i1 < MAXLAN - 1)	//跳过开头除字母的字符
		;
	while (!isalpha(s2[i2++]) && i1 < MAXLAN - 1)		//跳过开头除字母的字符
		;

	while ((s1[i1] == s2[i2]) && (s1[i1] != '\0' && s2[i2] != '\0'))
		++i1,++i2;

	if (s1[i1--] == s2[i2--])
		return 1;
	else
		return 0;
}