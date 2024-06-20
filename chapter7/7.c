/*Write a program that requests the hours worked in a week and then prints the gross pay, 
the taxes, and the net pay. Assume the following: 
 a. Basic pay rate = $10.00/hr 
 b. Overtime (in excess of 40 hours) = time and a half 
 c. Tax rate: #15% of the first $300 
20% of the next $150 
25% of the rest 
Use #define constants, and don’t worry if the example does not conform to current 
tax law.*/

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
    int command = 0;

    while (1) {
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                            2) $9.33/hr\n");
    printf("3) $10.00/hr                           4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");

    scanf("%d", &command);

    if (command < 1 || command > 5)
        continue;

    if (command == 5)
        break;

    switch (command){
    case 1:
        pay_rate = 8.75;
        break;
    case 2:
        pay_rate = 9.33;
        break;
    case 3:
        pay_rate = 10.00;
        break;
    case 4:
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