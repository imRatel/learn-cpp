#include <stdio.h>
#define Break 10   //行长度上限
#define MAX 1000


//把较长的行折成短行,折行的位置为Break之前的最后一个非空格处.
int main ()
{
	char line[MAX];
	int i,n_ch,ch;
	i = n_ch = ch = 0;

	while ((ch = getchar()) != EOF)
	{
		line[i] = ch;
		++i;
		++n_ch;
		
		if (ch == '\t')
			++n_ch;
		
		if (n_ch == Break)
		{
			for (n_ch = 0;line[i-1] == ' '||line[i-1] == '\t';--i)
				;
			
			line[i] = '\n';
			++i;
		}
	}

	line[i] = '\0';
	printf("%s",line);

	return 0;
}
