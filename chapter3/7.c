/*There are 2.54 centimeters to the inch. Write a program that asks you to enter your 
height in inches and then displays your height in centimeters. Or, if you prefer, ask for 
the height in centimeters and convert that to inches*/

#include <stdio.h>

int main (void){
    float amount;

    printf("Enter your height in cm: ");
    scanf ("%f", &amount);
    printf("Your height in inches is %f inches", amount / 2.54);

    return 0;
}