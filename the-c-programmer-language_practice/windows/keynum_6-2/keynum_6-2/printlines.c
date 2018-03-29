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

void printlines(struct tlines *lines)
{
	for (struct tlines *p = lines; p != NULL; p = p->next)
	{
		printf("%d. ", p->nline);
	}
}