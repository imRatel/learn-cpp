#include <stdio.h>
#include <string.h>

struct tree* treealloc();
char* wordrom(char *s);

struct tree
{
	char *word;
	int num;
	struct tree *lefttree;
	struct tree *righttree;
};

struct tree* addtree(struct tree *p, char *word)
{
	int n;
	if (p == NULL)
	{
		p = treealloc();
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
		p->righttree = addtree(p->righttree, word);
	}
	else if (n > 0)
	{
		p->lefttree = addtree(p->lefttree, word);
	}

	return p;
}