/*The harmonic mean of two numbers is obtained by taking the inverses of the two 
numbers, averaging them, and taking the inverse of the result. Write a function that 
takes two double arguments and returns the harmonic mean of the two numbers. */

#include <stdio.h>

double har_mean (double, double);

int main(void){
    double a;
    double b;

    printf("Enter two doubles: ");
    scanf("%lf %lf", &a, &b);

    printf("Harmonic mean is %lf", har_mean(a, b));
    return 0;
}

double har_mean(double a, double b){
    double average;

    a = 1/a;
    b = 1/b;
    
    average = (a + b)/2;

    return 1/average;
}