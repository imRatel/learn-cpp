#include <stdio.h>

int dilution(double concentration, int n = 0);

int main()
{
	char ch = 0;
	while (ch != EOF)
	{
		double enter = 0;
		printf_s("\n������Ŀ��Ũ�ȣ���λΪmg/ml��\nĿ��Ũ��Ϊ��");
		scanf_s("%lf", &enter);
		if (enter >= 10)
			printf_s("���̫���ˣ��Լ���ɡ�\n");
		if (enter <= 0)
			printf_s("��Ϲ�㡣\n");
		dilution(enter);
	}

	return 0;
}