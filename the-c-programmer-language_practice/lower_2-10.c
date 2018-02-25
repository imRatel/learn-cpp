/*************************************************************************
    > File Name: lower_2-10.c
    > Author: ratel
    > Mail: 920796548@qq.com 
    > Created Time: Sat Feb 24 19:55:46 2018
 ************************************************************************/

#include<stdio.h>
int lower (int c)
{
	(c >= 'A' && c <= 'Z')?return c + 'a' - 'A':return c;
}
