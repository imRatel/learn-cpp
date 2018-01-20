#include <stdio.h>
#include <math.h>
#define IN 0
#define OUT 1


main ()
{
	int control,n_white,i,x,y;
	long ch;
	int n_word[20];
	x=y=0;
	n_white=i=0;
	control=OUT;
	for(control=0;control<20;++control)         /*initialization n_word[0->20]=0*/
		n_word[control]=0;
	for(ch=getchar();ch!=EOF;ch=getchar())      /*if getchar=EOF,stop*/ 
	{
		if(ch!=' '&&ch!='\t'&&ch!='\n')			/*if getchar=char,add length and chanage state*/
		{
			++i;
			control=IN;
		}
		else if(control==IN)					//if chanage state,chanage again and add the number of this length
		{										//add n_white
			control=OUT;
			++n_word[i];
			i=0;
			++n_white;
		}
		else
			++n_white;
	}
	for(control=0;control<19;++control)			//compare the size between n_word[0->20] and n_white
	{
		if(n_word[control]>y)
			y=n_word[control];
		if(n_white>y)
			y=n_white;
	}
	for(y;y>=0;--y)								//output bar chart
	{
		for(x=1;x<=20;++x)
		{
			if(x==20)
			{
				if(y-n_white<0)
					printf("%c",219);
				else
					printf(" ");
			}
			else if(y-n_word[x]<0)
				printf("%-3c",219);
			else
				printf("   ");
		}
		putchar('\n');
	}
	for(control=1;control<=20;++control)
	{
		if(control==20)
			printf("W\n");
		else
			printf("%-3d",control);
	}
}
