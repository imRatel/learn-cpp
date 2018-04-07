#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void mainprintf(char *fmt, ...)
{
	va_list ap;
	char *fp,*sval,num[MAX];
	int ival,i,chval,wide,percision;
	double dval;

	va_start(ap, fmt);
	for (fp = fmt; *fp != '\0'; fp++)
	{
		wide = 0;			//初始化宽度
		percision = 0;		//初始化精度

		if(*fp != '%')
		{ 
			putchar(*fp);
			continue;
		}

		fp++;
		//判断是否有宽度限制
		if (*fp != '*')
		{
			for (i = 0; isdigit(*fp); i++)
			{
				num[i] = *fp;
				fp++;
			}
			num[i] = '\0';
			if (i > 0)
			{
				wide = atoi(num);
			}
		}
		else if (*fp == '*')
		{
			wide = va_arg(ap, int);
		}
		
		//判断是否有精度限制
		if (*fp == '.')
		{
			fp++;
			if (*fp != '*')
			{
				for (i = 0; isdigit(*fp); i++)
				{
					num[i] = *fp;
					fp++;
				}
			}
			else if(*fp == '*')
			{
				percision = va_arg(ap, int);
			}
			else
			{
				percision = 8;
			}
			if (i > 0)
			{
				percision = atoi(num);
			}
		}

		//判断是什么输出指令
		if (percision != 0)
		{
			switch (*fp)
			{
			case 'd':case'i':
				ival = va_arg(ap, int);
				printf("%*.*d",wide,percision, ival);
				break;
			case 'o':
				ival = va_arg(ap, int);
				printf("%*.*o", wide, percision, ival);
				break;
			case 'x':
				ival = va_arg(ap, int);
				printf("%*.*x", wide, percision, ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%*.*f", wide, percision, dval);
				break;
			case 's':
				sval = va_arg(ap, char*);
				printf("*.*%s", wide, percision, sval);
				break;
			case 'c':
				chval = va_arg(ap, char);
				putchar(chval);
				break;
			default:
				putchar(*fp);
				break;
			}
		}
		else
		{
			switch (*fp)
			{
			case 'd':case'i':
				ival = va_arg(ap, int);
				printf("%*d", wide, ival);
				break;
			case 'o':
				ival = va_arg(ap, int);
				printf("%*o", wide, ival);
				break;
			case 'x':
				ival = va_arg(ap, int);
				printf("%*x", wide, ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%*f", wide, dval);
				break;
			case 's':
				sval = va_arg(ap, char*);
				printf("%*s", wide, sval);
				break;
			case 'c':
				chval = va_arg(ap, char);
				putchar(chval);
				break;
			default:
				putchar(*fp);
				break;
			}
		}
	}
	va_end(ap);
}