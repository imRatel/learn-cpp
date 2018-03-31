#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* wordrom(char *s);

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

struct tword* addnum(struct tword *p, int num, char *word)
{
	if (p == NULL)
	{
		p = (struct tword*)malloc(sizeof(struct tword));
		p->lefttree = p->righttree = NULL;
		p->num = num;
		p->word = wordrom(word);
		if (p == NULL || p->word == NULL)
		{
			printf("error: the rom is full!");
		}
	}
	else if (num < p->num)
	{
		p->lefttree = addnum(p->lefttree, num, word);
	}
	else if (num > p->num)
	{
		p->righttree = addnum(p->righttree, num, word);
	}
	else if (num == p->num)
	{
		p->lefttree = addnum(p->lefttree, num, word);
	}

	return p;
}