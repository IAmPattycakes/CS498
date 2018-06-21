#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main()
{
    printf("%d\n", day_of_year(2018, 6, 21));
    printf("%d\n", day_of_year(2018, 6, 32));
    printf("%d\n", day_of_year(2018, 0, 21));
    int *month;
    int *day;
    month_day(2018, 0, month, day);
    printf("%d/%d\n", *month, *day);
    month_day(2018, 366, month, day);
    printf("%d/%d\n", *month, *day);
    month_day(2018, 173, month, day);
    printf("%d/%d\n", *month, *day);
}

static char daytab[2][13] = {
    {0, 31, 28,31,30,31,30,31,31,30,31,30,31},
    {0, 31, 29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{
    if(!(month < 1 || month > 12)) {
        int i, leap;
        leap = year % 4 == 0&& year % 100 != 0 || year % 400 == 0;
        if(daytab[leap][month] < day) {
            printf("Invalid day: %d\n", day);
            return -1;
        }
        for(i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    } else {
        printf("Invalid month: %d\n", month);
        return -1;
    }
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if(yearday < 1 || yearday > leap + 365) {
        printf("Invalid day: %d\n", yearday);
        *pmonth = -1;
        *pday = -1;
    } else {
        for(i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
}