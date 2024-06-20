/*Redo Review Question 5, but make the argument the spelled-out name of the month 
instead of the month number. (Don’t forget about strcmp().) Test the function in a 
simple program.*/

#include <stdio.h>
#include <string.h>

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

int days_passed(char *);

int main(void){
    char buffer[10] = "December";

    printf("Enter a month: ");
    scanf("%9s", buffer);

    while (getchar() != '\n')
        continue;

    printf("Days passed including this month: %i", days_passed(buffer));

    return 0;
}
int days_passed(char* month){
    int sum = 0;
    int i = 0;

    for(int i =0; i < 12; i++){
        if (strcmp(month, months[i].name))
            sum += months[i].days;
        else 
            return sum += months[i].days;
    }
    return -1;
}