#include <stdio.h>

void strcat(char *s1, char *s2)
{
	int n = 0;	//����ֵ�ַ�����ָ��λ��

	while (*(s1 + n) != '\0')	//��������ֵ�ַ����������ַ�
	{
		n = n + 1;
	}

	for (int i = 0; *(s2 + i) != '\0'; i = i + 1)	//��s2�е��ַ���ֵ��s1��ĩβ
	{
		*(s1 + n) = *(s2 + i);
		n = n + 1;
		*(s1 + n + 1) = '\0';
	}
}