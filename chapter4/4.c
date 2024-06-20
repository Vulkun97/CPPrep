/*Write a program that requests your height in inches and your name, and then displays 
the information in the following form: 
 Dabney, you are 6.208 feet tall 
Use type float, and use / for division. If you prefer, request the height in centimeters 
and display it in meters.*/

#include <stdio.h>
#include <string.h>

int main (void){
    float height;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your height in cm: ");
    scanf("%f", &height);
    printf("%s, you are %.2f meters tall", name, height/100);

    return 0;
}