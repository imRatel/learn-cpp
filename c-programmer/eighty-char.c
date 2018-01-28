#include <stdio.h>
#define MAX 1000

void savechar (char to[],char from[],int length);
int getline (char line[],int maxline);

int main ()
{
	char max_l[MAX],line[MAX];
	int length,t_l;
	length=t_l=0;

	while((length = getline(line,MAX)) > 0)
	{
		if(length>=5)
		{
		savechar(max_l,line,t_l);
		t_l += (length+1);
		}
															printf("%d  %d\n",t_l,length);
	}

	max_l[t_l] = '\0';
	printf("%s",max_l);

	return 0;
}

int getline (char line[],int maxline)
{
	int i,ch;
	
	for (i=0; i < maxline-1 && (ch=getchar()) != '\n' && ch!=EOF;++i)
	{
		line[i] = ch;
	}
	line[i]='\n';
															line[i+1]='\0';printf("%s\n",line);
	return i;
}

void savechar (char to[],char from[],int length)
{
	int i;

	for (i=0; from[i] != '\n' ;++i)
	{
		printf("%d\n",length);
		to[length] = from[i];
		++length;
		if(from[i]=='\n')
			printf("YES");
	}
									to[length]='\0';printf("%s\n%d\n",to,length);
	to[length] = '\n';
	
}
