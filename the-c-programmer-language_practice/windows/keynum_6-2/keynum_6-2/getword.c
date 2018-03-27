#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int ch);

int getword(char *word, int maxword)
{
	int ch;
	int i = 0;

	while (isspace(*word = ch = getch()))
		;

	if (ch == '*' && *word == '/')
	{
		while (*word != '*' && (ch = getch()) != '/')
		{
			*word = ch;
		}
		*word = '\0';
		return (int)NULL;
	}
	if (ch == '"')
	{
		while ((ch = getch()) != '"')
			;
		*word = '\0';
		return (int)NULL;
	}

	if (!isalpha(ch) && ch != '_' && ch != '#')
	{
		*word = '\0';
		return ch;
	}

	for (i = 1; (isalnum(ch = getch()) || ch == '_') && i < maxword; i++)
	{
		word[i] = ch;
	}
	if (i == maxword)
	{
		printf("error: enter is too much!");
	}
	ungetch(ch);

	word[i] = '\0';
	return word[0];
}