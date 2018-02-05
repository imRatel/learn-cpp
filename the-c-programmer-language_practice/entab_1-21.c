#include <stdio.h>
#define MAX 1000		//最大输入数
#define w_t 8				//TAB宽度
#define wide 120		//行宽度

int main ()
{
	int n_s,i,ch,n_ch;
	char line[MAX];
	n_s = i = ch = n_ch = 0;		//n_s记录了一个TAB宽度内输入了几个空格,n_ch记录一个TAB宽度内字符的数量

	while ((ch = getchar()) != EOF)		//当输入为EOF跳出整个循环
	{
		if (ch == ' ')		//在输入为空格的情况下,增加n_s,并判断字符加上空格是否已经达到一个TAB宽度,如果是就记录一个TAB
		{
			++n_s;
			
			if (n_s + n_ch == w_t )
			{
				line[i] = '\t';
				n_s = 0;
				n_ch = 0;
				++i;
			}
		}
		else							//如果输入不是空格,判断已经输入了多少个空格,并记录他们,然后记录当前输入的字符,最后判断
		{									//以输入的(除空格回车外的)字符宽度是否等于一个TAB宽度,如果是进入下一个TAB宽度中.
			for (;n_s > 0;--n_s)
			{
				line[i] = ' ';
				++i;
			}

			line[i] = ch;
			++i;
			++n_ch;

			if (n_ch == w_t || ch == '\n')
				n_ch = 0;
		}
	}
	line[i] = '\0';
	printf("%s",line);

	return 0;
}
