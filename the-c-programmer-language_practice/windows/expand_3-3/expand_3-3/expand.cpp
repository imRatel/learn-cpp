#include <stdio.h>
#define GAP 3  //测试左右有没有负号的范围
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

int replace(char *s, char ch1, char ch2, int k)  //替换速记符号并返回字符串下标值
{
	if (ch1 < ch2)
	{
		for (int n = 1; (ch1 + n) != ch2; ++n)
		{
			*(s + k) = ch1 + n;
			k++;
		}
	}
	else if (ch1 > ch2)
	{
		for (int n = 1; (ch1 - n) != ch2; ++n)
		{
			*(s + k) = ch1 - n;
			k++;
		}
	}
	else if (ch1 = ch2)
	{
		*(s + k) = ch1;
		k++;
	}
	return k-1;
}

void expand(char *s1, char *s2)
{
	int i, k, left, right;
	i = k = left = right = 0;

	for (i = 0; *(s1 + i) != '\0'; i = i + 1, k = k + 1)
	{	
		*(s2 + k) = *(s1 + i);
		
		if (*(s1 + i) == '-' && i > 0)
		{
			for (left = 1;left < GAP && *(s1 + i -left) != '-'; left = left + 1)
			{
				if (i - left < 0)
				{
					left = GAP - 1;
				}
			}

			for (right = 1; right < GAP && *(s1 + i + right) != '-'; right = right + 1)
				;


			if (left == GAP && right == GAP && is_A_or_a_or_i(*(s1 + i - 1),*(s1 + i + 1)))
			{
				switch (LandR(*(s1 + i - 1), *(s1 + i + 1)))
				{
				case SAME:
					k = replace(s2, *(s1 + i - 1), *(s1 + i + 1), k);
					break;
				case A_a:
					k = replace(s2, *(s1 + i - 1), 'Z', k);
					k = replace(s2, 'a', *(s1 + i + 1), k);
					break;
				case a_A:
					k = replace(s2, *(s1 + i - 1), 'z', k);
					k = replace(s2, 'A', *(s1 + i + 1), k);
					break;
				case NUM:
					k = replace(s2, *(s1 + i - 1), *(s1 + i + 1), k);
					break;
				}
			}
		}
	}
	
	*(s2 + k) = '\0';
}