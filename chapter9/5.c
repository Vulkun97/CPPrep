/*Write and test a function called larger_of() that replaces the contents of two double
variables with the maximum of the two values. For example, larger_of(x,y) would 
reset both x and y to the larger of the two.*/

#include <stdio.h>

void larger_of(double*, double*);

int main(void){
    double a;
    double b;

    printf("Enter two doubles: ");
    scanf("%lf %lf", &a, &b);
    larger_of(&a, &b);
    printf("%.2lf %.2lf", a, b);
}

void larger_of(double* a, double* b){
    if (*a > *b){
        *b = *a;
    }
    else {
        *a = *b;
    }
}