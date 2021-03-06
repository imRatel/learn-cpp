#include <stdio.h>
#include <ctype.h>

#define MAX 1000

struct tword_lines
{
	char *word;
	int num;
	struct tlines *lines;
	struct tword_lines *lefttree;
	struct tword_lines *righttree;
}*ptword_lines;
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
struct tlines
{
	int nline;
	struct tlines* next;
}*ptlines;

void printtree(struct tword *p);
void printroot(struct troot *p);;
int getword(char *word, int maxword);
struct tword* addword(struct tword *p, char *word);
struct troot* addroot(struct troot *p, char *word, int nroot);
struct tlines* foundlines(struct tlines* p, int nlines);
struct tlines* addlines(struct tlines* p, int nlines);
struct tword_lines* addword_lines(struct tword_lines *p, char *word, int lines);
void printword_lines(struct tword_lines *p);
struct tword* addnum(struct tword *p, int num, char *word);
struct tword* numsort(struct tword *p, struct tword *sortp);

int main()
{
	char word[MAX];
	int cond;
	struct tword *final = NULL;	
	struct tword *gradedown = NULL;
	int nroot = 2;
	int lines = 1;
	
	while ((cond = getword(word, MAX)) != EOF)
	{
		if (cond == '\n')
		{
			lines++;
		}

		if (isalpha(cond) || cond == '_' || cond == '#')
		{
			final = addword(final, word);
		}
	}

	gradedown = numsort(final,gradedown);
	printtree(gradedown);
	
	return 0;
}