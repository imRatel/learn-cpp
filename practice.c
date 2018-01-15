#include <stdio.h>
#include <math.h>

int main ()
{
	char ch_1,ch_2,ch_3;
	int b_1,b_2;
	printf("Please enter a char.\n");
	ch_1=getchar();
	getchar();
	printf("Please enter a char again.\n");
	scanf("%c\n",&ch_2);
	b_1=ch_1>='A'&&ch_1<='Z'||ch_1>='a'&&ch_1<='z';
	b_2=ch_2>='A'&&ch_2<='Z'||ch_2>='a'&&ch_2<='z';
	b_1?putchar('Y'):putchar('N');
	putchar('\n');
	ch_3=b_2?'Y':'N';
	printf("%c\n",ch_3);
	{
		printf("%d\n",ch_1);
		printf("%o\n",ch_1);
		printf("%x\n",ch_1);
		printf("%u\n",ch_1);
	}
	return 0;
}
