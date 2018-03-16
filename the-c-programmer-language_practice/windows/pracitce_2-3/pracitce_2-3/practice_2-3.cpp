#include <stdio.h>

#define MAX 1000
#define IN 1
#define OUT 0

int main()
{
	int state = OUT;
	int num[MAX];
	int ch, i, number;
	ch = i = number = 0;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if ((ch == 'x' || ch == 'X') && *(num + i) == '0')
		{
			state = IN;
			i = 0;
		}

		if (state == IN)
		{
			if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')
			{
				if (ch >= '0' && ch <= '9')
				{
					*(num + i) = ch - '0';
				}
				else if (ch >= 'a' && ch <= 'f')
				{
					*(num + i) = ch - 'a' + 10;
				}
				else if (ch >= 'A' && ch <= 'F')
				{
					*(num + i) = ch - 'A' + 10;
				}
				i = i + 1;
			}
		}
		else
		{
			*(num + i) = ch;
		}
	}
	i = i - 1;	//为了消除i自增1带来的冗余

	if (i <= 0)
	{
		printf("error :wrong number");
		return 0;
	}

	while (i >= 0)
	{
		number = number * 16 + *(num + i) ;
		i = i - 1;
	}
	printf("resule = %x", number);

	return 0;
}