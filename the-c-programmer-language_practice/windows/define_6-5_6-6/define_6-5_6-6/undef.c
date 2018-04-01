#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct deflist* LISTPTR;	//关于struct deflist的指针

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
LISTPTR indef(char *name, char *defn);

LISTPTR freelist(char *name, LISTPTR list)
{
	LISTPTR p;
	if (list != NULL)
	{
		list->next = freelist(name, list->next);
		if (strcmp(name, list->name) == 0)
		{
			free((void*)list->name);
			free((void*)list->defn);
			p = list->next;
			free((void*)list);
			list = p;
		}
		return list;
	}
	return NULL;
}

void undef(char *name)
{
	hashtab[hash(name)] = freelist(name, (hashtab[hash(name)]));
}