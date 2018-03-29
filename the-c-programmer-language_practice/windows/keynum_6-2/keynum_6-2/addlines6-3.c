#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tlines
{
	int nline;
	struct tlines *next;
};
struct tword_lines
{
	char *word;
	int num;
	struct tlines *lines;
	struct tword_lines *lefttree;
	struct tword_lines *righttree;
};

char* wordrom(char *s);
struct tlines* foundlines(struct tlines *p, int nlines);

struct tlines* addlines(struct tlines *p,int nlines)
{
	struct tlines *np;

	while ((np = foundlines(p, nlines)) == NULL)
	{
		np = (struct tlines*)malloc(sizeof(struct tlines));
		if (np == NULL)
		{
			printf("error: the struct is full!");
		}
		np->nline = nlines;

		np->next = p;
		p = np;
	}

	return np;
}