#include <stdio.h>
#include <string.h>


enum { PARENS, BRACKETS, NAME };
char token[];
extern int tokentype;
extern char out[];
extern char name[];
int gettoken();


void dcl()
{
	int np;

	for (np = 0; gettoken() == '*'; np++)
		;
	dirdcl();
	while (np > 0)
	{
		strcat(out, "指向 ");
		np--;
	}
}

void dirdcl()
{
	if (tokentype == '(')
	{
		dcl();
		if (tokentype != ')')
		{
			printf("error: ')' is not found!\n");
		}
	}
	else if (tokentype == NAME)
	{
		strcpy(name, token);
	}
	else
	{
		printf("error: dir-dcl is not found!");
	}

	while ((tokentype = gettoken()) == PARENS || tokentype == BRACKETS)
	{
		if (tokentype == PARENS)
		{
			strcat(out, "函数返回 ");
		}

		if (tokentype == BRACKETS)
		{
			strcat(out, "array");
			strcat(out, token);
			strcat(out, "是 ");
		}
	}
}