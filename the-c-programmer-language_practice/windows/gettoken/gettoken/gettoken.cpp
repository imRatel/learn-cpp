#include <stdio.h>
#include <ctype.h>

enum { PARENS, BRACKETS,NAME };
int getch();
void ungetch(int ch);
extern char token[];
extern int tokentype;

int gettoken()
{
	int c;
	int i;
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (c == '(')
	{
		c = getch();
		if (c == ')')
		{
			return tokentype = PARENS;
		}
		ungetch(c);
		return tokentype = '(';
	}
	else if (c == '[')
	{
		for (i = 0; (*(p + i) = c) != ']' && c != EOF; i++)
		{
			c = getch();
		}
		if (c == EOF)
		{
			printf("error: ']' is not found!\n");
			*(p + i - 1) = ']';
		}
		*(p + i) = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c))
	{
		for (i = 0; isalnum(*(p + i) = c); i++)
		{
			c = getch();
		}
		*(p + i) = '\0';
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}