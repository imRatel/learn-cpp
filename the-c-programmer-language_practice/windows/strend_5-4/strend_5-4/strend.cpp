/*����ַ���2,�������ַ���1��β��,����1,���򷵻�0*/

#include <stdio.h>
#include <string.h>

int strend(char *s1,char *s2)
{
	int n1, n2;		//ָ����ָ���ַ���1,2��λ��
	int s1_len,s2_len;	//�����ַ������Եĳ���
	n1 = n2 = 0;
	s1_len = strlen(s1);
	s2_len = strlen(s2);	//��ʼ��
	n1 = s1_len - s2_len;	//n1ָ��s1ĩβ,������Ӧ��s2���ȵ��ַ�

	while (*(s2 + n2) != '\0' && *(s1 + n1) == *(s2 + n2))
	{
		n1 = n1 + 1;
		n2 = n2 + 1;
	}

	if (*(s2 + n2) == '\0')
	{
		return 1;
	}
	return 0;
}