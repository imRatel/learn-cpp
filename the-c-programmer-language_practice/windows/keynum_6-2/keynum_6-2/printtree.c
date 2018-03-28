#include <stdio.h>

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

void printtree(struct tword *p)
{
	if (p != NULL)
	{
		printtree(p->lefttree);
		printf("%s :\t %d\n", p->word, p->num);
		printtree(p->righttree);
	}
}