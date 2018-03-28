#include <stdio.h>
#include <stdlib.h>

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

struct tword* treealloc()
{
	return (struct tword*)malloc(sizeof(struct tword));
}