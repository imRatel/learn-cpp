#include <stdio.h>
#include <string.h>

extern int reverse;

void swap(char *p[], int i, int j)
{
	char *temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void qsort(char *p[], int left, int right,int (*comp)(void*,void*))
{

	if (left >= right)
	{
		return;
	}

	swap(p, left, (left + right) / 2);
	int last = left + 1;
	for (int n = left; n <= right; n = n + 1)
	{
		if (reverse ? (comp(p[n], p[left]) > 0) : (comp(p[n], p[left]) < 0))
		{
			swap(p, last, n);
			last = last + 1;
		}
	}
	last = last - 1;
	swap(p, left, last);
	qsort(p, left, last - 1,comp);
	qsort(p, last + 1, right,comp);
}