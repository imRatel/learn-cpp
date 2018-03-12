#include <stdio.h>

int dilution(double concentration, int n = 0);

int main()
{
	char ch = 0;
	while (ch != EOF)
	{
		double enter = 0;
		scanf_s("%lf", &enter);
		dilution(enter);
	}

	return 0;
}