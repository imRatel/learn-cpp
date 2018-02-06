#include <stdio.h>
#define MAX 1000

int getline (char Line[],int maxline);
void save (char to[],char from[],int all_length);

int main ()
{
	int now,all_length;
	char line[MAX],all_line[MAX];
	
	now=all_length=0;

	while ((now = getline(line,MAX)) > 0)
	{
		if (line[0] != '\n')
		{
			save(all_line,line,all_length);
			all_length+=now+1;
		}
	}

	all_line[all_length]='\0';
	printf("%s",all_line);
	return 0;
}

int getline (char Line[],int maxline)
{
	int i,ch;

	for (i=0; (ch=getchar()) != '\n' && ch!=EOF && i<maxline-1 ;++i)
	{
		Line[i] = ch;
	}

	while (Line[i-1] == '\t' || Line[i-1] == ' ')
	{
		--i;
		if (i == 0)
		{
			Line[i]='\n';
			++i;
		}
	}

	Line[i]='\n';

	return i;
}

void save (char to[],char from[],int all_length)
{
	int i;

	for (i=0; from[i] != '\n';++i)
	{
		to[all_length] = from[i];
		++all_length;
	}

	to[all_length]='\n';
}
