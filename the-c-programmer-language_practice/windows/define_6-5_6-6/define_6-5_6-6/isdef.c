#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct deflist* LISTPTR;

struct deflist
{
	char *name;
	char *defn;
	LISTPTR next;
};

extern LISTPTR *hashtab[];
extern char *text;

LISTPTR founddef(char *name);
LISTPTR indef(char *name, char *defn);
int getword(char *word, int maxword);
unsigned hash(char *word);
char* wordrom(char *s);

int isdef()
{
	char word[MAX];
	char *name, *defn;
	int ch,i = 0;

	while ((ch = getword(word, MAX)) != '\n' && ch != EOF)
	{
		if(isalpha(ch) || ch == '_' || ch == '#')
		{
			if (i == 0)
			{
				name = wordrom(word);
			}
			defn = wordrom(word);
			i++;
		}
	}

	if (i == 2)
	{
		if (indef(name, defn) != NULL)
		{
			return 1;
		}
	}
	if (i > 2)
	{
		printf("error: the define is too much!\n");
	}
	if (i < 2)
	{
		printf("error: the define is too less!\n");
	}
	free(word);
	return 0;
}