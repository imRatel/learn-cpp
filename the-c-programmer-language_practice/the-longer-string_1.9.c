#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

//一个判定当前输入行的长度,并存储最大行和长度的程序
int getline (char line[],int maxline);
void copyline (char to[],char from[]);

int main ()
{
	int lin,max;								//lin为当前输入行的长度,max为当前最长行的长度
	char line[MAXLINE],longerlin[MAXLINE];		//line为当前输入的字符串,longerlin为当前最长的字符串
	
	control=lin=max=0;
	while ((lin=getline(line,MAXLINE))>0)		//如果当前输入行的长度小于零,判断是否大于最大行,是存储最大行并循环
	{											//否则,继续循环
		if (lin>max)
		{
			max=lin;
			copyline(longerlin,line);
		}
	}
	if (max>0)									//当跳出上面的输入循环,判断最大是否大于零,是则打印最大行字符串
		printf("\n%s",longerlin);
	
	printf("\n%d",max);							//打印最大行行数

	getchar();
	return 0;
}

//输入字符串并记录输入次数,最后返回输入次数
int getline (char line[],int maxline)
{
	int i,ch,max;

	for (max=0; (ch=getchar())!=EOF && ch!='\n'; ++max)	//记录输入次数和字符,在接收到结束和回车时跳出
	{
		if(max >= maxline-1)							//输入次数超过函数规定最大值时,只记录输入次数,并把输入的字符
		{												//改为回车
			ch='\n';
		}
		else											//没超过最大值,字符串增加当前字符
		{
			i=max;	//输入次数和字符数分离,保证字符串数据不超过函数规定
			line[i]=ch;
		}
	}
	
	if(ch==EOF)  //上面循环,退出时由于次数字符数分离导致结束时字符数少一,所以上述结束条件后字符数加一
		++i;

	if (ch=='\n')
	{
		++i;
		line[i]=ch;
		++i;
	}
	
	line[i]='\0'; //字符串结束
	return max;
}

//存储字符串
void copyline (char to[],char from[])
{
	int i;
	
	for (i=0; (to[i]=from[i]) != '\0'; ++i)
		;
}
