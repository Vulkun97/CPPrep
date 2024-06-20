/*Write a program that requests a type double number and prints the value of the number 
cubed. Use a function of your own design to cube the value and print it. The main()
program should pass the entered value to this function.*/

#include <stdio.h>

double cubed(double f);

int main (void){
    double cube;
    printf("Enter a number: ");
    scanf("%lf", &cube);

    printf("Cubed value is %.2f\n", cubed(cube));

    return 0;
}

double cubed(double f){
    return f * f * f;
}