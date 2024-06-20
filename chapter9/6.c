/*Write and test a function that takes the addresses of three double variables as arguments 
and that moves the value of the smallest variable into the first variable, the middle value 
to the second variable, and the largest value into the third variable. */

#include <stdio.h>

void sort_three(double*, double*, double*);
void swap(double*, double*);

int main(void){
    double a;
    double b;
    double c;

    printf("Enter three doubles: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    sort_three(&a, &b, &c);
    printf("Sorted: %.2lf, %.2lf, %.2lf", a, b, c);

    return 0;
}

void sort_three(double* a, double* b, double* c){
    (*a > *b) ? swap(a, b) : 1;
    (*b > *c) ? swap(b, c) : 1;
    (*a > *b) ? swap(a, b) : 1;
}

void swap(double* a, double* b){
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}