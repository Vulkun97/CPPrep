/*Modify Programming Exercise 8 from Chapter 7so that the menu choices are labeled by 
characters instead of by numbers; use q instead of 5 as the cue to terminate input. */

#include <stdio.h>
#define OVERTIME 0.5
#define TR_0_300 00.15
#define TR_300_450 00.05
#define TR_MORE_450 00.05

int main (void){
    float pay_rate = 0.0;
    unsigned int hours = 0;
    double gross_pay = 0.0;
    double taxes    = 0.0;
    char command = 0;

    while (1) {
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                            b) $9.33/hr\n");
    printf("c) $10.00/hr                           d) $11.20/hr\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");

    command = getchar();

    if (command == 'q')
        break;

    if (command < 'a' || command > 'd')
        continue;

    switch (command){
    case 'a':
        pay_rate = 8.75;
        break;
    case 'b':
        pay_rate = 9.33;
        break;
    case 'c':
        pay_rate = 10.00;
        break;
    case 'd':
        pay_rate = 11.20;
        break;
    }

    printf("Enter hours worked in a week: ");
    scanf ("%d", &hours);

    gross_pay = hours * pay_rate + (hours > 40 ? ((hours - 40) * (pay_rate * OVERTIME)) : 0);
    printf("Gross pay is %.2f\n", gross_pay);

    taxes = (gross_pay * TR_0_300) + (gross_pay > 300 ? (gross_pay - 300) * TR_300_450 : 0) + (gross_pay > 450 ? (gross_pay - 450) * TR_300_450 : 0);
    printf("Taxes is %.2f\n", taxes);

    printf("Net pay is %.2f\n\n", gross_pay - taxes);
    }
    
    printf("Done");

    return 0;

}