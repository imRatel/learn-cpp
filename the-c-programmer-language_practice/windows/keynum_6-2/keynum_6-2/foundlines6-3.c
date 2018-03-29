#include <stdio.h>

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

struct tlines* foundlines(struct tlines* p, int nlines)
{
	struct tlines* np;
	for (np = p;np != NULL;np = np->next)
	{
		if (np->nline == nlines)
		{
			return np;
		}
	}

	return NULL;
}