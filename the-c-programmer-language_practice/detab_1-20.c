#include <stdio.h>
#define n 32	//每一行的第四十二个字符为TAB终止
#define wide 120	//屏幕的字符宽度
#define MAX 10000	//最大输入的字符数

int main ()
{
	int a,ch,i,x,n_t;	//a记录当前行以输入字符的数量TAB除外 n_t用来记录当前TAB位置距离下一个终止能容纳几个TAB
	char line[MAX];
	a = ch = i = x = n_t = 0;

	while ((ch=getchar()) != EOF) //输入EOF时,整个程序终止并打印detab后的文本
	{
		if (ch == '\n')					//先判断是否换行,如果换行就初始化a和n_t
		{
			a = 0;
			line[i]=ch;
			++i;
			n_t = 0;
		}
		else if (ch == '\t')			//如果上面为否,判断是否为TAB
		{
			if (n_t > 0)					//如果是,先判断是否已经进行过detab,如果是n_t自减一,并跳出
				--n_t;
			else if (n > a)					//如果上面为否,判断当前字符位置是否在终止之前
			{
				if (n-a % 4 == 0)				//上,是,判断当前位置,并记录与终止有几个TAB距离
					n_t = (n-a) / 4;
				else 
					n_t = (n-a) / 4 + 1;
			
				for (;n > a;++a,++i)			//输出相应数量的空格
					line[i] = ' ';
			}
			else							//上面为否,判断当前位置,并记录与终止有几个TAB距离
			{
				x = wide - a + n;	

				if (x-a % 4 == 0)
					n_t = (x-a) / 4;
				else 
					n_t = (x-a) / 4 + 1;
				
				for (a = 0; x > a;++i,++a)		//并输出相应数量的空格
					line[i] = ' ';	

				a = n;
			}
		}
		else						//上面都为否,记录当前字符
		{
			line[i] = ch;
			++i;
			++a;
			n_t = 0;
		}
	}

	line[i] = '\0';
	printf("%s",line);

	return 0;
}
