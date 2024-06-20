/*The 1988 United States Federal Tax Schedule was the simplest in recent times. It had 
four categories, and each category had two rates. Here is a summary (dollar amounts are 
taxable income): 
 Category Tax 
 Single 15% of first $17,850 plus 28% of excess 
Head of Household 15% of first $23,900 plus 28% of excess 
Married, Joint 15% of first $29,750 plus 28% of excess 
Married, Separate 15% of first $14,875 plus 28% of excess 
For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850 
+ 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category 
and the taxable income and that then calculates the tax. Use a loop so that the user can 
enter several tax cases.*/

#include <stdio.h>
#define SINGLE      17850.00
#define HH          23900.00
#define MARRIED_J   29750.00
#define MARRIED_S   14875.00

#define TR_STANDART 0.15
#define TR_EXCESS   (0.28 - 0.15)

int main (void){
    int category;
    double tax_cut;
    double income;
    double taxes;

    while (1) {
    printf("******************************\n");
    printf("Enter your category or action:\n");
    printf("1) Single: \n");
    printf("2) Head of Household\n");
    printf("3) Maried, Joint\n");
    printf("4) Married, Separate\n");
    printf("5) Quit\n");
    printf("******************************\n");

    scanf("%d", &category);

    if (category < 1 || category > 5)
        continue;

    if (category == 5)
        break;

    switch (category){
    case 1:
        tax_cut = SINGLE;
        break;
    case 2:
        tax_cut = HH;
        break;
    case 3:
        tax_cut = MARRIED_J;
        break;
    case 4:
        tax_cut = MARRIED_S;
        break;
    }

    printf("Enter your income: ");
    scanf ("%lf", &income);

    taxes = income * TR_STANDART + (income > tax_cut ? (income - tax_cut) * TR_EXCESS : 0);

    printf("Taxes is %.2lf\n", taxes);
    }
    
    printf("Done");

    return 0;

}