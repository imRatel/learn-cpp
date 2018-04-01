#include <stdio.h>
#include <string.h>

#define MAX 100
#define HASHSIZE 101

typedef struct deflist* LISTPTR;	//关于struct deflist的指针

struct deflist
{
	char *name;
	char *defn;
	LISTPTR next;
};

LISTPTR hashtab[HASHSIZE + 1];

int getword(char *word, int maxword);
char* define(char *word);
int isdef();

void stringcat(char *s1, char *s2)
{
	int n = 0;	//被赋值字符串的指针位置

	while (s1[n] != '\0')	//跳过被赋值字符串的已有字符
	{
		n = n + 1;
	}

	for (int i = 0; *(s2 + i) != '\0'; i = i + 1)	//把s2中的字符赋值到s1的末尾
	{
		s1[n] =s2[i];
		n = n + 1;
	}
	s1[n] = '\0';

};

int main()
{
	char word[MAX],text[MAX*MAX];
	char *pword;
	int ch;
	int def = 0;
	*text = '\0';

	while ((ch = getword(word, MAX)) != EOF)
	{
		if (strcmp(word, "#define") == 0)
		{
			def = def + isdef();
			*word = '\0';
		}
		if (def > 0 && *word != '\0')
		{
			pword = define(word);
		}
		if (*pword != '\0')
		{
			stringcat(text,pword);
		}
		free(pword);
	}

	printf("%s", text);
	return 0;
}