#include <stdio.h>

int getline(char *line, int maxlen)//读取字符串
{
	int ch, n = 0;
	while ((ch = getchar()) != '\n' && ch != EOF && n < maxlen - 1)
	{
		*(line + n) = ch;
		n = n + 1;
	}

	if (n == maxlen - 1)	//当输入数量等于最大上限时,报错并返回
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