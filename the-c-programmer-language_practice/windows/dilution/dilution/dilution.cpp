#include <stdio.h>

#define ERROR 0 //表示错误
#define SUCCESS 1 //表示成功
#define FIRST 2	//表示第一次成功
#define END 99	//表示最后一次进行
#define MAXTEST 2	//最大稀释次数
#define BOTTLENUM 8	//不同容积瓶子的数量
#define VALVENUM 7	//不同容积移液管的数量

static int bottle[BOTTLENUM] = { 1,2,5,10,20,25,50,100 }; //各个容量瓶的容积
static int valve[VALVENUM] = { 1,2,3,5,10,15,25 };	//各个移液管的容积

int dilution(double concentration, int n = 0)
{
	int state;
	if (concentration > 5.0 && concentration < 15.0) //如果得到结果为范围内返回第一次成功
		return FIRST;
	else if (n <= MAXTEST) //判断稀释次数是否小于最大稀释次数
	{
		for (int i_VAL = 0; i_VAL < VALVENUM; i_VAL++) //测试容量瓶
		{
			for (int i_BOT = 0; i_BOT < BOTTLENUM ;i_BOT++)	//测试移液管
			{
				double now_con = concentration / valve[i_VAL] * bottle[i_BOT]; //获得的状态,并进行下一次稀释
				state = dilution(now_con, n + 1); //当前稀释浓度
				if (state == FIRST)
				{
					if (i_VAL != 0 || i_BOT > 5)
						return ERROR;
					else
					{
						printf("\n取 %.4fmg 的标品 , 用 %dml 容量瓶稀释 , 得到浓度 %.4fmg/ml 的标品\n", now_con, bottle[i_BOT],concentration);
						return SUCCESS;
					}
				}
				else if (state == SUCCESS)
				{
					if (i_BOT != 0)
					printf("--->	再从当前 %.4fmg/ml 浓度中吸取 %dml 溶液 , 加入至 %dml 容量瓶中稀释 , 得到浓度 %.4fmg/ml 的标品\n", now_con,valve[i_VAL],bottle[i_BOT],concentration);
					return SUCCESS;
				}
			}
		}
	}
	return ERROR;
}