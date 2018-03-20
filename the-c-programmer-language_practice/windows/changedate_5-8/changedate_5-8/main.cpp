#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int *pmonth, int *pday);

int main()
{
	int day, yearday, month,year;
	printf("please enter year,month,day.\n");
	scanf_s("%d%d%d", &year, &month, &day);

	yearday = day_of_year(year, month, day);
	printf("year:%d  day:%d\n", year, yearday);
	month_day(year, yearday, &month, &day);
	printf("year:%d month:%d day:%d\n", year, month, day);
	return 0;
}