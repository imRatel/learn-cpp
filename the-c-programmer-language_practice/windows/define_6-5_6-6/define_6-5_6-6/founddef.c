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

LISTPTR founddef(char *name)
{
	LISTPTR p;

	for ((p = hashtab[hash(name)]); p != NULL; p = p->next)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p;
		}
	}

	return NULL;
}

