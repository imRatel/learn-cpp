#pragma once
#define MAXOP 100 //�����������㷴Ӧ����󳤶�
#define MAXVAL 100	//��ջ�������
#define VARIABLE 'a'//���Ϊ����
#define NUMBER '0'	//���Ϊ����
#define COMMAND 1	//���Ϊ����
#define ERROR 2		//���Ϊ����
#define ASSIGNMENT 3//���Ϊ��ֵ

#define FULL 'F'		//��ʾ״̬��
#define EMPTY 'E'		//��ʾ״̬��

#define VAL_print_top 4		//��ӡ���ϲ�ֵ
#define VAL_copy_top 5		//�������ϲ�ֵ
#define VAL_swap_top 6		//������������������ֵ
#define VAL_clear 7			//��ն�ջ
#define SIN 8				//���Һ���
#define COS 9				//���Һ���
#define TAN 10				//���к���
#define POW 11				//�η�����
#define FABS 12				//����ֵ����

int  getop(char s[], char line[]);	//��ȡ������
void push(double f);	//�ѵ�ǰ����ѹ���ջ
double pop();			//��ȡһ����ջֵ
int iscommand(char s[]);//�ж���ʲô����
int linecmp(char s1[], char s2[]);	//�ж������ַ����Ƿ����		!!ע��!!�˺��������ַ�����ͷ�ķ���ĸ�ַ�
void getline(char line[]);	//��ȡһ����
