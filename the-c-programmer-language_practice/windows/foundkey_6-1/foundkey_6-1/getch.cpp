#include <stdio.h>

#define EMPTY 0
#define FULL 1

static int last;
static int state;

int getch()
{
	if (state == EMPTY)
	{
		return getchar();
	}

	state = EMPTY;
	return last;
}

void ungetch(int ch)
{
	state = FULL;
	last = ch;
}