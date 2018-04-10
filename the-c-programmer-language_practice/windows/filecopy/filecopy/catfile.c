#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

FILE* filecopy(FILE *fp1, FILE *fp2);

FILE* catfile(char *filename[],char *lastname)
{
	FILE *fp;
	FILE *lastfp;
	int i = 0;

	if (filename[i] == NULL)
	{
		fprintf("error: file name is empty!",stderr);
		return NULL;
	}

	lastfp = fopen(lastname, 'w');
	fp = fopen(filename[i], 'r');
	filecopy(fp,lastfp);

	lastfp = fopen(lastname, 'a');
	for (i = 1; filename[i] != NULL; i++)
	{
		if (fp = fopen(filename[i], 'r') == NULL)
		{
			printf("")
		}
		filecopy(fp, lastfp);
	}
	
	return lastfp;
}