#include <stdio.h>
#include <ctype.h>

#define MAXLAN 100	//��������󳤶�

int linecmp(char s1[],char s2[])//�ж������ַ����Ƿ����		!!ע��!!�˺��������ַ�����ͷ�ķ���ĸ�ַ�
{
	int i1, i2;
	i1 = i2 = 0;

	while (!isalpha(s1[i1++]) && i1 < MAXLAN - 1)	//������ͷ����ĸ���ַ�
		;
	while (!isalpha(s2[i2++]) && i1 < MAXLAN - 1)		//������ͷ����ĸ���ַ�
		;

	while ((s1[i1] == s2[i2]) && (s1[i1] != '\0' && s2[i2] != '\0'))
		++i1,++i2;

	if (s1[i1--] == s2[i2--])
		return 1;
	else
		return 0;
}