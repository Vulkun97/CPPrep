/*Chuckie Lucky won a million dollars (after taxes), which he places in an account that 
earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a 
program that finds out how many years it takes for Chuckie to empty his account. */

#include <stdio.h>

int main (void){
    double account = 1000000.0;
    int years = 0;

    do {
        account *= 1.08;
        account -= 100000.0;
        years++;
    } while (account > 0);

    printf("Withdrawing took %d years", years);

    return 0;
}