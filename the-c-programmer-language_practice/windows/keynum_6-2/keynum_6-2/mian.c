#include <stdio.h>

#define MAX 100

struct tree
{
	char *word;
	int num;
	struct tree *lefttree;
	struct tree *righttree;
}*ptree;

void printtree(struct tree *p);
struct tree* addtree(struct tree *p, char *word);
int getword(char *word, int maxword);

int main()
{
	char word[MAX];
	int cond;
	
	while ((cond = getword(word, MAX)) != EOF)
	{
		if (cond != (int)NULL)
		{
			ptree = addtree(ptree, word);
		}
	}
	printtree(ptree);
	
	return 0;
}