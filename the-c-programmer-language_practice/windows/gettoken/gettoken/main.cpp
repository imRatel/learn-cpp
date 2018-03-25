#include <stdio.h>
#include <string.h>

#define MAX 100

enum { PARENS, BRACKETS, NAME };
char token[MAX];
int tokentype;
char out[MAX];
char name[MAX];
char datetype[MAX];
int gettoken();
void dcl();
void dirdcl();

int main()
{
	while (gettoken() != EOF)
	{
		strcat(datetype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
		{
			printf("enter error!\n");
		}
		printf("%s : %s %s", name, out, datetype);
	}
	return 0;
}

