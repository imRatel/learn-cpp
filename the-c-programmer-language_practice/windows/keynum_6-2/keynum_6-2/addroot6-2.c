#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char* wordrom(char *s);
struct tword* addword(struct tword *p, char *word);

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

struct troot* addroot(struct troot *p, char *word, int nroot)
{
	int n;
	char root[MAX];
	if (p == NULL)
	{
		p = (struct troot*)malloc(sizeof(struct troot));
		strncpy_s(root, strlen(word) + 1, word, nroot);
		p->roots = wordrom(root);
		p->left = p->right = NULL;
		p->root_word = NULL;

		p->root_word = addword(p->root_word,word);
		if (p->roots == NULL)
		{
			printf("error: the rom is full!");
		}
	}
	else if ((n = strncmp(p->roots, word,nroot)) == 0)
	{
		p->root_word = addword(p->root_word, word);
	}
	else if (n < 0)
	{
		p->right = addroot(p->right, word,nroot);
	}
	else if (n > 0)
	{
		p->left = addroot(p->left, word, nroot);
	}

	return p;
}