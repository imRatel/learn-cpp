#include <stdio.h>
#include <string.h>

extern struct key {
	const char *word;
	int num;
};

int keytype(char *word, struct key tab[], int nkey)
{
	int left = 0, right = nkey - 1,mid;
	int i = 0;

	while (left < right)
	{
		mid = (right + left) / 2;
		if (strcmp(word, tab[mid].word) >= 0)
		{
			if (strcmp(word, tab[mid].word) == 0)
			{
				return mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}