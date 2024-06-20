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

unsigned int days_passed(unsigned int mn);

int main(void){
    char buffer[10] = "December";

    printf("Enter a month: ");
    scanf("%9s", buffer);

    while (getchar() != '\n')
        continue;

    for(int i = 0; i < 12; i++){
        if (strcmp(months[i].name, buffer) == 0){
            printf("Days passed including this month: %u", days_passed(i+1));
            return 0;
        }
    }
}

unsigned int days_passed(unsigned int mn){
    unsigned int sum = 0;

    for (int i = 0; i < mn; i++) {
        sum += months[i].days;
    }

    return sum;
}