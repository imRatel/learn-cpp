#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 //�����������㷴Ӧ����󳤶�
#define MAXLAN 100	//��������󳤶�
#define NUMBER '0'	//���Ϊ����
#define COMMAND 1	//���Ϊ����
#define ERROR 2		//���Ϊ����
#define ASSIGNMENT 3//���Ϊ��ֵ

#define VAL_print_top 4		//��ӡ���ϲ�ֵ
#define VAL_copy_top 5		//�������ϲ�ֵ
#define VAL_swap_top 6		//������������������ֵ
#define VAL_clear 7			//��ն�ջ

int  getop(char s[]);	//��ȡ������
void push(double f);	//�ѵ�ǰ����ѹ���ջ
double pop();			//��ȡһ����ջֵ

int main()	//�沨��������
{
	//��Ҫ�Լ�дһ���ж���ʲô����ĺ���
	//������Ҫ��ԭ��������ӷ�֧,��ֵ�����֧,�����֧,������֧,�����֧
}