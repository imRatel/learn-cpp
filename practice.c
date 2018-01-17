#include <stdio.h>
#include <math.h>
#define PI 3.1415


main ()
{
	long a,b;
	b=0;
	for(a=getchar();a!=EOF;a=getchar())
	{
		if(a=='\t')
			printf("\\t");
		if(a=='\b')
			printf("\\b");
		if(a!='\t'&&a!='\b')
			putchar(a);
	}
	printf("%ld",b);
}
