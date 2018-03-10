#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 //�����������㷴Ӧ����󳤶�
#define MAXVAL 100	//��ջ�������
#define VARIABLE 'a'//���Ϊ����
#define NUMBER '0'	//���Ϊ����
#define COMMAND 1	//���Ϊ����
#define ERROR 2		//���Ϊ����
#define ASSIGNMENT 3//���Ϊ��ֵ


#define VAL_print_top 4		//��ӡ���ϲ�ֵ
#define VAL_copy_top 5		//�������ϲ�ֵ
#define VAL_swap_top 6		//������������������ֵ
#define VAL_clear 7			//��ն�ջ
#define SIN 8				//���Һ���
#define COS 9				//���Һ���
#define TAN 10				//���к���
#define POW 11				//�η�����
#define FABS 12				//����ֵ����

int  getop(char s[],char line[]);	//��ȡ������
void push(double f);	//�ѵ�ǰ����ѹ���ջ
double pop();			//��ȡһ����ջֵ
int iscommand(char s[]);//�ж���ʲô����
int linecmp(char s1[], char s2[]);	//�ж������ַ����Ƿ����		!!ע��!!�˺��������ַ�����ͷ�ķ���ĸ�ַ�
void getline(char line[]);	//��ȡһ����

int n_line = 0;			//��������еļ���

int main()	//�沨��������
{
	int type;	//�������Ӧ�Ĳ�������
	double op2,op3;	//��ʱ��Ų���
	char s[MAXOP];			//��������Ĳ���
	double var[MAXOP + 'z'];	//�������
	double last = 0.0;			//��һ�δ�ӡ��ֵ
	char line[MAXOP];		//���������
	
	getline(line);

	while ((type = getop(s,line)) != EOF)
	{
		switch (type)
		{
		case NUMBER:	//Ϊ����,ѹ���ջ
			push(atof(s));
			break;
		case '+':		//Ϊ�ӷ�
			push(pop() + pop());
			break;
		case '*':		//Ϊ�˷�
			push(pop() * pop());
			break;
		case '-':		//Ϊ����
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':		//Ϊ����
			op2 = pop();
			push(pop() / op2);
			break;
		case '%':		//Ϊ����
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case '\n':		//��ӡ������ֵ,������
			last = pop();
			printf("end\t=%.8g\n",last);
			break;

		case COMMAND:	//Ϊ�����
			switch (iscommand(s))
			{
			case VAL_print_top:	
				printf("\nVAL top = %.8g\n", last = op2 = pop());
				push(op2);
				break;
			case VAL_copy_top:
				push(op2 = pop());
				push(op2);
				break;
			case VAL_swap_top:
				op2 = pop();
				op3 = pop();
				push(op3);
				push(op2);
				break;
			case VAL_clear:
				for (int i = 0; i < MAXVAL; i++)
					pop();
				break;
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				push(tan(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case FABS:
				push(fabs(pop()));
				break;
			case ERROR:
				printf("\nnot found this older\n");
				break;
			}
			break;

		case ASSIGNMENT:	//Ϊ��ֵ
			var['z' - s[0]] = pop();
			break;
		case VARIABLE:		//Ϊ����
			push(var['z' - s[0]]);
			break;

		case ERROR:
			printf("\nnot found this older\n");
			break;
		}
	}

	return 0;
}