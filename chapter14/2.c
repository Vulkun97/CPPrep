/*Write a program that prompts the user to enter the day, month, and year. The month 
can be a month number, a month name, or a month abbreviation. The program then 
should return the total number of days in the year up through the given day. (Do take 
leap years into account.)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct month {
    char name [10];
    char abbrevation[4];
    unsigned int days;
    unsigned int number;
};

struct month months[12] = {
    {"January", "JAN", 31, 1},
    {"February", "FEB", 28, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 31, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12},
};

int days_passed(int, int);

int month_to_int(char*);

void is_leap_year(int);

int valid_date(int, int, int);

int main(void){
    int day;
    char month_buff[10];
    int year;
    int month;

    int passed;

    printf("Enter the day, month, and year: ");
    scanf("%d %9s %d", &day, month_buff, &year);
    while (getchar() != '\n')
        continue;
    while(valid_date(day, (month = month_to_int(month_buff)), year)){
        printf("Enter correct the day, month, and year: ");
        scanf("%d %9s %d", &day, month_buff, &year);
        while (getchar() != '\n')
            continue;
    }

    is_leap_year(year);

    passed = days_passed(day, month);

    printf("Days passed: %d days", passed);

    return 0;
}

int month_to_int(char* month){
    if (month[1] == '\0' || month[2] == '\0'){
        return atoi(month) < 13 ? atoi(month) : -1;
    }

    if (month[3] == '\0'){
        for (int i = 0; i < 12; i++)
            if (strcmp(month, months[i].abbrevation) == 0)
                return months[i].number;
    }
    else {
        for (int i = 0; i < 12; i++)
            if (strcmp(month, months[i].name) == 0)
                return months[i].number;
    }

    return -1;
}

int valid_date(int day , int month, int year){
    if (month < 0 || month > 12)
        return -1;

    if (day > months[month].days)
        return -1;

    return 0;
}

void is_leap_year(int year){
    months[1].days = 28;

    if (year % 4 == 0)
        months[1].days = 29;

    if (year / 100 > 0 && year % 400 == 0)
        months[1].days = 29;
}

int days_passed(int days, int month){
    int sum = 0;

    for(int i = 0; i < month - 1; i++){
            sum += months[i].days;
    }
    return sum + days;
}