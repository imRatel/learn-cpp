#include <stdio.h>

int calender[][13] = { { 0,31,28,31,30,31,30,31,31,30,31,30,31 } ,
						{ 0,31,29,31,30,31,30,31,31,30,31,30,31 } };

int day_of_year(int year, int month, int day)
{
	int leap = 0;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		leap = 1;
	}

	if (month > 12)
	{
		printf("error: The month is too large!");
		return 0;
	}
	if (day > calender[leap][month])
	{
		printf("error: The day is too large!");
		return 0;
	}

	while (month > 0)
	{
		month = month - 1;
		day =day + calender[leap][month];
	}

	return day;
}