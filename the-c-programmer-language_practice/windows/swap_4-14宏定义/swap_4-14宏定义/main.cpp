#include <stdio.h>

#define swap(t,x,y) t = x;x = y;y = t;

int main()
{
	int a, b, c;
	b = 100;
	c = 0;
	swap(a, b, c);
	printf("%d\n%d", b, c);

	return 0;
}