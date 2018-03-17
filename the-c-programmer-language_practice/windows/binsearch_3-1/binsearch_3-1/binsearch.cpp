#include <stdio.h>

int binsearch(int x, int *v, int n)	//’€∞Î≤È’“
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = (high + low) / 2;

	while (low <= high && x != *(v + mid))
	{
		mid = (high + low) / 2;
		x < *(v + mid) ? high = mid - 1 : low = mid + 1;
	}
	if (x == *(v + mid))
		return mid;
	else
		return -1;
}