/*Modify exercise 8 so that it uses a function to return the value of the calculation.*/

#include <stdio.h>

double calculation (double d1, double d2);

int main(void){
    double num1 = 0;
    double num2 = 0;

    printf("Enter two float numbers: ");
    scanf("%lf %lf", &num1, &num2);

    while (num1 != 0 && num2 != 0) {
        printf("The value of difference divided by product of these numbers is %lf\n",
        calculation(num1, num2));

        num1 = 0;
        num2 = 0;
        
        printf("Enter two float numbers: ");
        scanf("%lf %lf", &num1, &num2);
    }
    printf("Done\n");

    return 0;
}

double calculation (double d1, double d2){
    return (d1 - d2) / (d1 * d2);
}