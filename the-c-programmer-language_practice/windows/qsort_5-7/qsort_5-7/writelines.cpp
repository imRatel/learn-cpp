#include <stdio.h>

void writeline(char *p[], int nline) //����ַ�������ָ�������Ӧ�����ַ���
{
	if (nline < 0)
	{
		printf("error: The number is wrong!(n != 0)");
		return;
	}

	for (int np = 0; np <= nline; np = np + 1)
	{
		printf("%s\n", p[np]);
	}
}