#include <stdio.h>
#include <ctype.h>

#define NKEY (sizeof(keytab) / sizeof(keytab[0]))
#define MAX 100

struct key {
	const char *word;
	int num;
}keytab[] = 
{
	{ "#a",0 } ,{ "_a",0 } ,{"a",0},{ "b",0 } ,{"c",0}, {"d",0}
};

int keytype(char *word, struct key tab[], int nkey);
int gettoken(char *word, int maxword);

int main()
{
	int n;
	char word[MAX];

	while (gettoken(word, MAX) != EOF)
	{
		if (isalnum(word[0]) || word[0] == '#' || word[0] == '_')
		{
			if ((n = keytype(word, keytab, NKEY)) >= 0)
			{
				(keytab[n].num)++;
			}
		}
	}

	for (int i = 0; i < NKEY; i++)
	{
		printf("%s : %d\n", keytab[i].word, keytab[i].num);
	}
	return 0;
}