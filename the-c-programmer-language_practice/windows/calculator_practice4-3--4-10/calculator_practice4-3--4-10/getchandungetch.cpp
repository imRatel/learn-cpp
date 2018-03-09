#include <stdio.h>

#define FULL 1
#define EMPTY 0

int ch = EMPTY;
int s_getch = EMPTY;

int getch()
{
	switch (s_getch)
	{
	case FULL:
		s_getch = EMPTY;
		if (ch == EOF)
			return ch;
		else
			return (char)ch; 
		break;
	case EMPTY:
		return getchar();
		break;
	}
}

void ungetch(int c)
{
	switch (s_getch)
	{
	case FULL:
		printf("ungetch : too many char!");
		break;
	case EMPTY:
		ch = c;
		s_getch = FULL;
		break;
	}
}


