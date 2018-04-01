#include <stdio.h>

#define HASHSIZE 101

unsigned hash(char *word)
{
	int hashnum = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		hashnum = hashnum * 31 + word[i];
	}

	return hashnum % HASHSIZE;
}