#include <stdio.h>

void writeline(char *p[], int nline) //输出字符串数组指针里的相应数量字符串
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