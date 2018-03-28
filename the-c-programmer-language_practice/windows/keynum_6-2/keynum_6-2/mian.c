#include <stdio.h>

#define MAX 100

struct tword
{
	char *word;
	int num;
	struct tword *lefttree;
	struct tword *righttree;
}*ptword;

struct troot
{
	char *roots;
	struct tword* root_word;
	struct troot* left;
	struct troot* right;
}*ptroot;

void printtree(struct tword *p);
void printroot(struct troot *p);;
int getword(char *word, int maxword);
struct tword* addword(struct tword *p, char *word);
struct troot* addroot(struct troot *p, char *word, int nroot);

int main()
{
	char word[MAX];
	int cond;
	struct troot* final = NULL;	
	int nroot = 2;
	
	while ((cond = getword(word, MAX)) != EOF)
	{
		if (cond != (int)NULL)
		{
			final = addroot(final, word,nroot);
		}
	}
	printroot(final);
	
	return 0;
}