#include <stdio.h>

#define ERROR 0 //��ʾ����
#define SUCCESS 1 //��ʾ�ɹ�
#define FIRST 2	//��ʾ��һ�γɹ�
#define END 99	//��ʾ���һ�ν���
#define MAXTEST 2	//���ϡ�ʹ���
#define BOTTLENUM 8	//��ͬ�ݻ�ƿ�ӵ�����
#define VALVENUM 7	//��ͬ�ݻ���Һ�ܵ�����

static int bottle[BOTTLENUM] = { 1,2,5,10,20,25,50,100 }; //��������ƿ���ݻ�
static int valve[VALVENUM] = { 1,2,3,5,10,15,25 };	//������Һ�ܵ��ݻ�

int dilution(double concentration, int n = 0)
{
	int state;
	if (concentration > 5.0 && concentration < 15.0) //����õ����Ϊ��Χ�ڷ��ص�һ�γɹ�
		return FIRST;
	else if (n <= MAXTEST) //�ж�ϡ�ʹ����Ƿ�С�����ϡ�ʹ���
	{
		for (int i_VAL = 0; i_VAL < VALVENUM; i_VAL++) //��������ƿ
		{
			for (int i_BOT = 0; i_BOT < BOTTLENUM ;i_BOT++)	//������Һ��
			{
				double now_con = concentration / valve[i_VAL] * bottle[i_BOT]; //��õ�״̬,��������һ��ϡ��
				state = dilution(now_con, n + 1); //��ǰϡ��Ũ��
				if (state == FIRST)
				{
					if (i_VAL != 0 || i_BOT > 5)
						return ERROR;
					else
					{
						printf("\nȡ %.4fmg �ı�Ʒ , �� %dml ����ƿϡ�� , �õ�Ũ�� %.4fmg/ml �ı�Ʒ\n", now_con, bottle[i_BOT],concentration);
						return SUCCESS;
					}
				}
				else if (state == SUCCESS)
				{
					if (i_BOT != 0)
					printf("--->	�ٴӵ�ǰ %.4fmg/ml Ũ������ȡ %dml ��Һ , ������ %dml ����ƿ��ϡ�� , �õ�Ũ�� %.4fmg/ml �ı�Ʒ\n", now_con,valve[i_VAL],bottle[i_BOT],concentration);
					return SUCCESS;
				}
			}
		}
	}
	return ERROR;
}