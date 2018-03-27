#include <stdio.h>
#include <stdlib.h>

struct tree
{
	char *word;
	int num;
	struct tree *lefttree;
	struct tree *righttree;
};

struct tree* treealloc()
{
	return (struct tree*)malloc(sizeof(struct tree));
}