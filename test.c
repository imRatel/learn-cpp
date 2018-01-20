#include <stdio.h>

main ()
{
	int n[20],y;
	int control;
	y=0;
	for(control=0;control<20;++control)
	{
		scanf("%d",&n[control]);
	}
	for(control=0;control<20;++control)
		if(n[control]>y)
			y=control;
	printf("%d ",y);
	
}
