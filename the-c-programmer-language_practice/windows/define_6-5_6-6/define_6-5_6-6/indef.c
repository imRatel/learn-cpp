#include <stdio.h>
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
char* wordrom(char *s);

LISTPTR indef(char *name,char *defn)
{
	LISTPTR p;
	int hashnum;
	if ((p = founddef(name)) == NULL)
	{
		p = (LISTPTR)malloc(sizeof(struct deflist));
		p->next = NULL;
		p->name = wordrom(name);
		p->defn = wordrom(defn);

		hashnum = hash(name);	//把让next指向上个定义，表头指向当前定义
		p->next = hashtab[hashnum];
		hashtab[hashnum] = p;
	}
	else
	{
		free((void*)p->defn);
		p->defn = wordrom(defn);
	}

	if (p == NULL || p->defn == NULL || p->name == NULL)
	{
		printf("error: thr rom is full!\n");
		return NULL;
	}

	return p;
}