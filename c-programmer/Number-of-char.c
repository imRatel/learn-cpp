#include <stdio.h>
#include <math.h>

#define L_A 65	//letter 'A'
#define L_a 97	//letter 'a'
#define N_0 48	//number '0'
#define N_l 26	//number of letter
main ()
{
	long ch;
	int n_cl[N_l],n_l[N_l],n_N[10];
	int n_white,n_others,control,x,y;
	n_white=n_others=y=0;

	for(control=0;control<N_l;++control)
		n_cl[control]=n_l[control]=0;

	for(control=0;control<10;++control)
		n_N[control]=0;

	for(ch=getchar();ch!=EOF;ch=getchar())
	{
		if(ch>='A'&&ch<='Z')
			++n_cl[ch-L_A];
		else if(ch>='a'&&ch<='z')
			++n_l[ch-L_a];
		else if(ch>='0'&&ch<='9')
			++n_N[ch-N_0];
		else if(ch==' '||ch=='\t'||ch=='\n')
			++n_white;
		else 
			++n_others;
	}

	for(control=0;control<N_l;++control)
	{
		if(control<10)
		{
			if(y<n_N[control])
				y=n_N[control];
		}
		
		if(y<n_cl[control])
			y=n_cl[control];
		
		if(y<n_l[control])
			y=n_l[control];
	}

	for(control=y;control>0;--control)
	{
		for(x=0;x<N_l;++x)
		{
			if(n_cl[x]-control>=0)
				printf("%-2c",219);
			else
				printf("  ");
			
			if(n_l[x]-control>=0)
				printf("%-2c",219);
			else
				printf("  ");
		}
		
		for(x=0;x<10;++x)
		{
			if(n_N[x]-control>=0)
				printf("%c",219);
			else
				printf(" ");
		}
		
		if(n_white-control>=0)
			printf("%2c",219);
		else
			printf("  ");
		
		if(n_others-control>=0)
			printf("%2c",219);
		else
			printf("  ");
		
		printf("\n");
	}

	for(control=0;control<N_l+10;++control)
	{
		if(control<N_l)
			printf("%-2c%-2c",control+L_A,control+L_a);
		if(control>=N_l)
			printf("%d",abs(N_l-control));
	}

	printf(" W O");
}
