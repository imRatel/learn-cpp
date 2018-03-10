#include <stdio.h>
#include <ctype.h>

#define MAXLAN 100	//��������󳤶�
#define NUMBER '0'	//���Ϊ����
#define COMMAND 1	//���Ϊ����
#define ERROR 2		//���Ϊ����
#define ASSIGNMENT 3//���Ϊ��ֵ
#define VARIABLE 'a'//���Ϊ����

int getch(char line[]);				//��ȡһ���ַ�
void ungetch(int ch);		//ѹ��һ���ַ�

int isnumsign(int ch)	//�ж��Ƿ�Ϊ������������(+,-,*,/,%)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 1;
	else
		return 0;
}

int  getop(char s[], char line[])	//��ȡһ��������
{
	int i, ch;
	i = ch = 0;

	while ((s[0] = ch = getch(line)) == ' ' || ch == '\t')	//�����ո��
		;
	
	s[1] = '\0';
	
	if (isnumsign(ch) || ch == '\n' || ch == EOF)	//��������Ϊ��Ч����������ʱ���ظò�����
	{
			return ch;
	}
	
	if (ch == '=')	//��ǰ����Ϊ�Ⱥ�ʱ,�ж��Ƿ�Ϊ��ֵ����,���Ƿ��ظ�ֵ���,���򷵻ش�����Ϣ		s[0]Ϊ�ñ���������
	{
		while (isalpha(s[i++] = ch = getch(line)))	//���ǵȺ�
			;

		if (i > 2)
		{
			printf(" \n'='so mang char for VARIABLE \n");
			return ERROR;
		}

		s[1] = '\0';
		ungetch(ch);
		return ASSIGNMENT;
	}

	if (isalpha(ch))	//Ϊ�����Ǽ�¼�������������
	{
		while (isalpha(s[++i] = ch = getch(line)) && i < 20)
			;

		if (i <= 2 && isalpha(s[i-1]))	//Ϊ�������ر������	s[0]Ϊ�ñ���������
		{
			s[1] = '\0';
			ungetch(ch);
			return VARIABLE;
		}

		s[i] = '\0';
		ungetch(ch);
		return COMMAND;
	}

	if (isdigit(ch))	//Ϊ����ʱ��¼���ֲ��������ֱ��
	{
		while (isdigit(s[++i] = ch = getch(line)))
			;

		if (ch == '.')
			while (isdigit(s[++i] = ch = getch(line)));

		s[i] = '\0';
		ungetch(ch);
		return NUMBER;
	}

	printf("\nerror : input error!\n");
	return ERROR;
}