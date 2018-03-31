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
		printtree(p->righttree);
		printf("%d��\t %s\n",  p->num,p->word);
		printtree(p->lefttree);
	}
}