#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

void strcpy(char *p1, char *p2);
char* alloc(int n);

int getargv(char *argv[]) //»ñÈ¡Ö¸Áî
{
	int argc = 0,ch = 0,i;
	char now[MAX];

	while (ch != '\n' &&ch != EOF)
	{
		for (i = 0; !isspace(ch = getchar()); i++)
		{
			now[i] = ch;
		}
		now[i] = '\0';
		if (i > 0)
		{
			argv[argc] = alloc(i);
			strcpy(argv[argc],now);
			argc++;
		}
	}
	argv[argc] = alloc(1);
	*argv[argc] = '\0';

	return argc;
}