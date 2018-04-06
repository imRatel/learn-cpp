#include <stdio.h>

#define MAX 100

static char last[MAX];
static int state;

int getch()
{
	if (state == 0)
	{
		return getchar();
	}

	state--;
	return last[state];
}

int  ungetch(int ch)
{
	if (state == MAX - 1)
	{
		return NULL;
	}
	last[state] = ch;
	state++;
	return state;
}