#include <stdio.h>

int getline(char *line, int maxlen)//��ȡ�ַ���
{
	int ch, n = 0;
	while ((ch = getchar()) != '\n' && ch != EOF && n < maxlen - 1)
	{
		*(line + n) = ch;
		n = n + 1;
	}

	if (n == maxlen - 1)	//���������������������ʱ,��������
	{
		printf("error: The line is full!");
		*(line + n) = '\0';
		return n;
	}

	if (n == 0)
	{
		return 0;
	}

	*(line + n) = ch;
	n = n + 1;
	*(line + n) = '\0';

	return n;
}