/*Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns 
an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest 
compounded annually. (That is, interest is 5% of the current balance, including previous 
addition of interest.) Write a program that finds how many years it takes for the value 
of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two 
values at that time.*/

#include <stdio.h>

int main (void){
    double invest1 = 100.0;
    double invest2 = 100.0;
    int years = 0;

    do {
        invest1 += 10.0;

        invest2 *= 1.05;

        years++;

    } while (invest1 > invest2);

    printf ("invest2 exceeded invest1 in %d years\n", years);
    printf ("invest1 is %10.2lf\n", invest1);
    printf ("invest2 is %10.2lf", invest2);
    

    return 0;
}