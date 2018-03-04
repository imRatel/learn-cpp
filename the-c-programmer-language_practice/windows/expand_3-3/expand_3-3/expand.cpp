#include <stdio.h>
#define INI 3  //初始化n的值
#define END 0  //n的结束值
#define A_a 1  //左大写右小写
#define a_A 2  //左小右大
#define SAME 3  //左右相同
#define NUM 4 //是数字
int is_A_or_a_or_i(char ch1, char ch2) //判断是否是合法字符
{
	int rt = 0;
	rt = ((ch1 >= 'a' && ch1 <= 'z' || ch1 >= 'A' && ch1 <= 'Z' || ch1 >= '0' && ch1 <= '9') && (ch2 >= 'a' && ch2 <= 'z' || ch2 >= 'A' && ch2 <= 'Z' || ch2 >= '0' && ch2 <= '9') 
		&& !(ch1 == 'z' && ch2 == 'A') && !(ch1 == 'Z' && ch2 == 'a') && (ch1+1 != ch2) && (ch1-1 != ch2));
	return rt;
}

int LandR(char ch1, char ch2)  //判断左右字符大小写,数字
{
	if ((ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z') || (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z'))
		return SAME;
	else if (ch1 >= '0' && ch1 <= '9' && ch2 >= '0' && ch2 <= '9')
		return NUM;
	else if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')
		return a_A;
	else if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z')
		return A_a;
	else
		return 0;
}

int replace(char s[], char ch1, char ch2, int k)  //替换速记符号并返回字符串下标值
{
	if (ch1 < ch2)
	{
		for (int n = 1; (ch1 + n) != ch2; ++n)
		{
			s[k++] = ch1 + n;
		}
	}
	else if (ch1 > ch2)
	{
		for (int n = 1; (ch1 - n) != ch2; ++n)
		{
			s[k++] = ch1 - n;
		}
	}
	else if (ch1 = ch2)
	{
		s[k++] = ch1;
	}
	return k-1;
}

void expand(char s1[], char s2[])
{
	int i, k, n;
	char line[1000];
	i = k = 0;
	
	for (int x = 3; x>=0; x--)
	{
		line[k++] = ' ';
	}

	while (s1[i] != '\0')
	{
		if (s1[i] == '-' && i > 0)
		{
			for (n = INI; (s1[i - n] != '-' || s1[i + n] != '-') && n != END; --n)
				;
			if (!n && is_A_or_a_or_i(s1[i - 1],s1[i + 1]))
			{
				switch (LandR(s1[i - 1], s1[i + 1]))
				{
				case SAME:
					k = replace(line, s1[i - 1], s1[i + 1], k);
					break;
				case A_a:
					k = replace(line, s1[i - 1], 'Z', k);
					k = replace(line, 'a', s1[i + 1], k);
					break;
				case a_A:
					k = replace(line, s1[i - 1], 'z', k);
					k = replace(line, 'A', s1[i + 1], k);
					break;
				case NUM:
					k = replace(line, s1[i - 1], s1[i + 1], k);
					break;
				}
				++k, ++i;
			}
		}
		else
			line[k++] = s1[i++];
	}
	line[k] = '\0';

	for (int x = k - 4; x >= 0; x--,k--)
	{
		s2[x] = line[k];
	}
}