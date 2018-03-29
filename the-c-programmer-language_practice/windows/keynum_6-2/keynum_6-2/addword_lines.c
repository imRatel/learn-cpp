#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* wordrom(char *s);
struct tlines* foundlines(struct tlines* p, int nlines);
struct tlines* addlines(struct tlines* p, int nlines);

struct tlines
{
	int nline;
	struct tlines *next;
};
struct tword_lines
{
	char *word;
	int num;
	struct tlines *lines;
	struct tword_lines *lefttree;
	struct tword_lines *righttree;
};

struct tword_lines* addword_lines(struct tword_lines *p, char *word,int lines)
{
	int n;
	if (p == NULL)
	{
		p = (struct tword_lines*)malloc(sizeof(struct tword_lines));
		p->word = wordrom(word);
		p->num = 1;
		p->lefttree = p->righttree = NULL;
		p->lines = NULL;
		p->lines = addlines(p->lines, lines);
		if (p->word == NULL)
		{
			printf("error: the rom is full!");
		}
	}
	else if ((n = strcmp(p->word, word)) == 0)
	{
		(p->num)++;
		p->lines = addlines(p->lines, lines);
	}
	else if (n < 0)
	{
		p->righttree = addword_lines(p->righttree, word,lines);
	}
	else if (n > 0)
	{
		p->lefttree = addword_lines(p->lefttree, word,lines);
	}

	return p;
}