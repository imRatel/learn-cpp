#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* wordrom(char *s);

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

struct tword* addword(struct tword *p, char *word)
{
	int n;
	if (p == NULL)
	{
		p = (struct tword*)malloc(sizeof(struct tword));
		p->word = wordrom(word);
		p->num = 1;
		p->lefttree = p->righttree = NULL;
		if (p->word == NULL)
		{
			printf("error: the rom is full!");
		}
	}
	else if ((n = strcmp(p->word, word)) == 0)
	{
		(p->num)++;
	}
	else if (n < 0)
	{
		p->righttree = addword(p->righttree, word);
	}
	else if (n > 0)
	{
		p->lefttree = addword(p->lefttree, word);
	}

	return p;
}