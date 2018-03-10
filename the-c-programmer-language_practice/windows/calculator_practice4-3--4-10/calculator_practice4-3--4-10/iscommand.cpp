#include <stdio.h>
#include <string.h>

#define MAXLIB 100
#define ERROR 2
#define VAL_print_top 4		//��ӡ���ϲ�ֵ
#define VAL_copy_top 5		//�������ϲ�ֵ
#define VAL_swap_top 6		//������������������ֵ
#define VAL_clear 7			//��ն�ջ
#define SIN 8				//���Һ���
#define COS 9				//���Һ���
#define TAN 10				//���к���
#define POW 11				//�η�����
#define FABS 12				//����ֵ����

int linecmp(char s1[], char s2[]);//�ж������ַ����Ƿ����		!!ע��!!�˺��������ַ�����ͷ�ķ���ĸ�ַ�

char command[MAXLIB][MAXLIB];	//��������Ӧ���ַ����Ĵ�������

void commandlib ()	//��������������Ӧ�ַ����ĺ���
{
	strcpy_s(command[4], "print");
	strcpy_s(command[5], "copy");
	strcpy_s(command[6], "swap");
	strcpy_s(command[7], "clear");
	strcpy_s(command[8], "sin");
	strcpy_s(command[9], "cos");
	strcpy_s(command[10], "tan");
	strcpy_s(command[11], "pow");
	strcpy_s(command[12], "fabs");
}

int iscommand(char s[]) //�ж��Ƿ�Ϊ����,���򷵻���Ӧ�������ʶֵ
{
	int i = 4; //i����Ӧ�������ʶ��ֵ

	commandlib();

	while (i < 13)
	{
		if (linecmp(s, command[i++]))
			return --i;   //������Ӧ�������ʶ��ֵ
	}

	return ERROR;
}