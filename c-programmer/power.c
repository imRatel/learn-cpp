#include <stdio.h>
#include <math.h>

int power (int a,int b);

int main ()
{
	int IN_a,IN_b;

	printf("Please enter two numbers(base,indes)\n");		//底数和指数
	scanf("%d%d",&IN_a,&IN_b);
	printf("%d",power(IN_a,IN_b));

	return 0;
}

int power (int a,int b)
{
	int control,p=1;

	for(control=0;control<b;++control)
		p=p*a;

	if(b==0&&a!=0)
		p=1;

	return p;
}
