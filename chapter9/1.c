/*Devise a function called min(x,y) that returns the smaller of two double values. Test 
the function with a simple driver.*/

#include <stdio.h>

double min(double, double);

int main (void){
    double a;
    double b;

    printf("Enter two float values: ");
    scanf("%lf %lf", &a, &b);

    printf("The smaller one is %.2lf", min(a,b));

    return 0;
}

double min(double a, double b){
    return (a<b) ? a : b;
}