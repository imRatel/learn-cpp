#include <stdio.h>

#define MAXVAL 100

int n_val = 0; //��ջ��ǰ��Ŀ
double val[MAXVAL]; //��ջ,�����ĿΪ100

void push(double f) //�ѵ�ǰ����ѹ���ջ,������,���ش�����Ϣ
{
	if (n_val < MAXVAL)
	{
		val[n_val++] = f;
	}
	else
		printf("\nerror:The val is already full!\n");
}

double pop() //ȡ����ջ�����������,����ջ��ʱ����0.0,��������ʾ
{
	if (n_val > 0)
	{
		return val[--n_val];
	}
	else
	{
		printf("\nwaring:The val is empy!");
		return 0.0;
	}
}