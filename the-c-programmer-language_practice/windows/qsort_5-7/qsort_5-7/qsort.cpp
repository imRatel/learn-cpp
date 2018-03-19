#include <stdio.h>
#include <string.h>

void swap(char *p[], int i, int j);

void qsort(char *p[], int left, int right)
{
	
	if (left >= right)
	{
		return;
	}

	swap(p,left,(left + right)/2);
	int last = left + 1;
	for (int n = left; n <= right; n = n + 1)
	{
		if (strcmp(p[n], p[left]) < 0)
		{
			swap(p, last, n);
			last = last + 1;
		}
	}
	last = last - 1;
	swap(p, left, last);
	qsort(p, left, last - 1);
	qsort(p, last+1, right);
}