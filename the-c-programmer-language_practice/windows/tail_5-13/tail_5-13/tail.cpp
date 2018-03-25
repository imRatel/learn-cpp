#include <stdio.h>
#include <stdlib.h>

int tail(int argc,char* argv[],char* line[],int nline)
{
	int pargv = 1;
	int npri = 10;
	if (*(argv[pargv]) = '-')
	{
		npri = -atof((argv[pargv]));
		pargv = pargv + 1;
	}
	
	while (npri > 0)
	{
		if (nline < 0)
		{
			printf("\n");
		}
		else
		{
			printf("%s\n", line[nline - npri + 1]);
		}

		npri = npri - 1;
	}

	return nline;
}              