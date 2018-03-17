#include <stdio.h>
#define MAX 100

int binsearch(int x, int *v, int n);

int main()
{
	int x = 4;
	int v[MAX];
	for (int i = 0; i != MAX; ++i)
		v[i] = i;
	int back = binsearch(x, v, MAX);
	return 0;
}