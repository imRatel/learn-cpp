#include <stdio.h>

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

void printlines(struct tlines *lines);

void printword_lines(struct tword_lines *p)
{
	if (p != NULL)
	{
		printword_lines(p->lefttree);
		printf("%s :\t %d\nline : ", p->word, p->num);
		printlines(p->lines);
		putchar('\n');
		printword_lines(p->righttree);
	}
}