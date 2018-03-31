#include <stdio.h>

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

struct tword* addnum(struct tword *p, int num, char *word);

struct tword* numsort(struct tword *p,struct tword *sortp)
{
	if (p != NULL)
	{
		sortp = numsort(p->lefttree,sortp);
		sortp = addnum(sortp, p->num, p->word);
		sortp = numsort(p->righttree, sortp);
		return sortp;
	}
	return sortp;
}