#include <stdio.h>

#define YEARDAY 365

extern int *calender[];

void month_day(int year, int day, int *pmonth, int *pday)
{
	int leap = 0;
	int n = 0;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		leap = 1;
	}

	if (day > YEARDAY + leap)
	{
		printf("error: The day is too large!");
		return;
	}

	while (day > 0)
	{
		n = n + 1;
		day = day - *((*calender + leap) + n);
	}

	day = day + *((*calender + leap) + n);
	
	*pmonth = n;
	*pday = day;
}