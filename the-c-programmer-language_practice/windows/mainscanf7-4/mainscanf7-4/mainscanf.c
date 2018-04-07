#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void mainscanf(char *fmt, ...)
{
	va_list ap;
	char *fp;
	char *chval,sval[100];
	int *ival;
	double *dval;
	char ch;

	va_start(ap, fmt);
	for (fp = fmt; *fp != '\0'; fp++)
	{
		while (*fp != '%')
		{
			while ((ch = getchar()) == *fp && ch != EOF)
				;
			fp++;
		}
		fp++;
		switch (*fp)
		{
		case 'd':case'i':
			ival = va_arg(ap, int*);
			scanf_s("%d", ival);
			break;
		case 'o':
			ival = va_arg(ap, int*);
			scanf_s("%o", ival);
			break;
		case 'x':
			ival = va_arg(ap, int*);
			scanf_s("%x", ival);
			break;
		case 'f':
			dval = va_arg(ap, double*);
			scanf_s("%lf", dval);
			break;
		case 's':
			scanf_s("%s", sval,100);
			strcpy_s(va_arg(ap, char*), strlen(sval) + 1, sval);
			break;
		case 'c':
			chval = va_arg(ap, char*);
			scanf_s("%1c", chval);
			break;
		default:
			return;
		}
	}
	va_end(ap);
}