#include <stdio.h>

extern struct tree
{
	char *word;
	int num;
	struct tree *lefttree;
	struct tree *righttree;
};

void printtree(struct tree *p)
{
	if (p != NULL)
	{
		printtree(p->lefttree);
		printf("%s :\t %d\n", p->word, p->num);
		printtree(p->righttree);
	}
}