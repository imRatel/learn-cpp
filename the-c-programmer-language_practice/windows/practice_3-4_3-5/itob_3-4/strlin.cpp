#include <stdio.h>

int strlen(char s[]) //�ж��ַ������� ������\0
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i - 1;
}