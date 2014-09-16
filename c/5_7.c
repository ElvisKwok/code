#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (month > 12 || month < 1 || daytab[leap][month] < day)
        return 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (yearday > (365+leap) || yearday <= 0) {
        *pmonth = 0;
        *pday = 0;
    }
    else {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
}


int main()
{
    int year=2014, month=2, day=29, yearday;
    yearday = day_of_year(year, month, day);
    month_day(year, yearday, &month, &day);
    printf("%d, %d, %d\n", yearday, month, day);
    return 0;
}
