#include <stdio.h>

#define ERROR 0 //��ʾ����
#define SUCCESS 1 //��ʾ�ɹ�
#define FIRST 2	//��ʾ��һ�γɹ�
#define MAXTEST 4	//���ϡ�ʹ���
#define BOTTLENUM 8	//��ͬ�ݻ�ƿ�ӵ�����
#define VALVENUM 7	//��ͬ�ݻ���Һ�ܵ�����

int bottle[BOTTLENUM] = { 2,5,10,15,20,25,50,100 }; //��������ƿ���ݻ�
int valve[VALVENUM] = { 1,2,3,5,10,15,25 };	//������Һ�ܵ��ݻ�

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