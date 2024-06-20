/*Write a program that requests two floating-point numbers and prints the value of their 
difference divided by their product. Have the program loop through pairs of input values 
until the user enters nonnumeric input. */

#include <stdio.h>

int main(void){
    double num1 = 0;
    double num2 = 0;

    printf("Enter two float numbers: ");
    scanf("%lf %lf", &num1, &num2);

    while (num1 != 0 && num2 != 0) {
        printf("The value of difference divided by product of these numbers is %lf\n",
        (num1 - num2)/ (num1 * num2));

        num1 = 0;
        num2 = 0;
        
        printf("Enter two float numbers: ");
        scanf("%lf %lf", &num1, &num2);
    }
    printf("Done\n");

    return 0;
}