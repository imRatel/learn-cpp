#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int getargv(char *argv[]) //»ñÈ¡Ö¸Áî
{
	int argc = 0, ch = 0, i;
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
			if ((argv[argc] = malloc(i + 1)) == NULL)
			{
				printf("error: the rom is full!\n");
			}
			else
			{
				strcpy_s(argv[argc], strlen(now) + 1, now);
				argc++;
			}
		}
	}
	argv[argc] = malloc(1);
	*argv[argc] = '\0';

	return argc;
}