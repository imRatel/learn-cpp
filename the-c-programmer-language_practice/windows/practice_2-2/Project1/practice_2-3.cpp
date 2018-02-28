#include <stdio.h>
#define MAX 1000
#define IN 1
#define OUT 0

int main()
{
	int first = IN;
	int state = OUT;
	int num[MAX];
	char line[MAX];
	int ch, i, x, control, number;
	for (x = MAX; x >= 0; x--)
	{
		num[x] = 0;
	}
	ch = i = x = control = number = 0;

	while ((ch = getchar()) != '\n' && ch != '`')
	{
		if (state == IN)
		{
			if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')
			{
				if (first == OUT)
				{
					for (x = control; x >= 0; x--)
					{
						num[x] *= 16;
					}
					control++;
				}
				else
					first = OUT;

				if (ch >= '0' && ch <= '9')
					num[control] = ch - '0';
				else if (ch >= 'a' && ch <= 'f')
					num[control] = ch - 'a' + 9;
				else if (ch >= 'A' && ch <= 'F')
					num[control] = ch - 'A' + 9;

				line[i] = ch;
				++i;
			}
		}
		else if ((ch == 'x' || ch == 'X') && line[i] == '0')
		{
			state = IN;
			++i;
			line[i] = ch;
			++i;
		}
		else
			line[i] = ch;
	}

	while (control >= 0)
	{
		number += num[control];
		control--;
	}
	if (i <= 3)
		printf("error :wrong number");
	else
		printf("%s = %d", line, number);
	return 0;
}