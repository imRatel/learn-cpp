/*如果字符串2,出现在字符串1的尾部,返回1,否则返回0*/

#include <stdio.h>
#include <string.h>

int strend(char *s1,char *s2)
{
	int n1, n2;		//指针所指向字符串1,2的位置
	int s1_len,s2_len;	//两个字符串各自的长度
	n1 = n2 = 0;
	s1_len = strlen(s1);
	s2_len = strlen(s2);	//初始化
	n1 = s1_len - s2_len;	//n1指向s1末尾,倒数相应于s2长度的字符

	while (*(s2 + n2) != '\0' && *(s1 + n1) == *(s2 + n2))
	{
		n1 = n1 + 1;
		n2 = n2 + 1;
	}

	if (*(s2 + n2) == '\0')
	{
		return 1;
	}
	return 0;
}