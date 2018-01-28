#include <stdio.h>
#define MAX 1000

int getline (char line[],int maxline);
void reverse (char line[],int len);

int main ()
{
	char now[MAX];
	int len;
	len=0;

	while ((len = getline(now,MAX)) > 0 )
	{
		reverse(now,len);
	}

	return 0;
}

int getline (char line[],int maxline)
{
	int ch,i;

	for (i=0; (ch=getchar()) != '\n' && ch != EOF && i < maxline-1;++i)
	{
		line[i] = ch;
	}

	line[i] = '\0';

	return i;
}

void reverse (char line[],int len)
{
	int i;
	char r_line[len];

	for (i=0; i != len;++i)
	{
		r_line[i] = line[len-i-1];
	}

	r_line[i] = '\0';
	printf("%s\n",r_line);
}
