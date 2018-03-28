#include <stdio.h>

void printtree(struct tword *p);

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
};

struct troot
{
	char *roots;
	struct tword* root_word;
	struct troot* left;
	struct troot* right;
};


void printroot(struct troot *p)
{
	if (p != NULL)
	{
		printroot(p->left);
		printtree(p->root_word);
		printroot(p->right);
	}
}