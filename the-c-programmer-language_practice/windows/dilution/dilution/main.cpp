#include <stdio.h>

int dilution(double concentration, int n = 0);

int main()
{
	char ch = 0;
	while (ch != EOF)
	{
		double enter = 0;
		printf_s("\n请输入目标浓度，单位为mg/ml。\n目标浓度为：");
		scanf_s("%lf", &enter);
		if (enter >= 10)
			printf_s("这个太简单了，自己算吧。\n");
		if (enter <= 0)
			printf_s("别瞎搞。\n");
		dilution(enter);
	}

	return 0;
}