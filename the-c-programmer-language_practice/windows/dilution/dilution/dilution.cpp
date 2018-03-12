#include <stdio.h>

#define ERROR 0 //表示错误
#define SUCCESS 1 //表示成功
#define FIRST 2	//表示第一次成功
#define MAXTEST 4	//最大稀释次数
#define BOTTLENUM 8	//不同容积瓶子的数量
#define VALVENUM 7	//不同容积移液管的数量

int bottle[BOTTLENUM] = { 2,5,10,15,20,25,50,100 }; //各个容量瓶的容积
int valve[VALVENUM] = { 1,2,3,5,10,15,25 };	//各个移液管的容积

int dilution(double concentration, int n = 0)
{
	if (concentration > 5.0 && concentration < 15.0)
		return FIRST;
	else if (n <= MAXTEST)
	{
		for (int i_VAL = 0; i_VAL < VALVENUM; i_VAL++)
		{
			for (int i_BOT = 0; i_BOT < BOTTLENUM; i_BOT++)
			{
				dilution(concentration / i_VAL * i_BOT, n + 1);
			}
		}
	}
}