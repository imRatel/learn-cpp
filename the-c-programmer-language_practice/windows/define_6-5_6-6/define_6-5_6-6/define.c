#include <stdio.h>
#include <string.h>

typedef struct deflist* LISTPTR;

struct deflist
{
	char *name;
	char *defn;
	LISTPTR next;
};

extern LISTPTR hashtab[];

unsigned hash(char *word);
char* wordrom(char *s);
LISTPTR founddef(char *name);

char* define(char *word)
{
	LISTPTR p;
	if ((p = founddef(word)) != NULL)
	{
		word = wordrom(p->defn);
	}
	return word;
}