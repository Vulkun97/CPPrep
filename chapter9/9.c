/*Redo Programming Exercise 8, but this time use a recursive function.*/

#include <stdio.h>

double power (double, int);

int main(void){
    double number;
    int pow;

    printf("Enter float number and its power as integer: ");
    scanf("%lf %d", &number, &pow);
    printf("Answer is %lf", power(number, pow));
    return 0;
}

double power(double n, int p){
    double pow = 1;

    if (p == 0){
        return 1;
    }

    if (n == 0){
        return 0;
    }

    if (p > 0)
        return n * power(n, p - 1);
    else
        return (1/n) * power(n, p + 1);
}