/*Write a program that asks the user to enter a height in centimeters and then displays the 
height in centimeters and in feet and inches. Fractional centimeters and inches should 
be allowed, and the program should allow the user to continue entering heights until a 
nonpositive value is entered. A sample run should look like this: 
 Enter a height in centimeters: 182
 182.0 cm = 5 feet, 11.7 inches
 Enter a height in centimeters (<=0 to quit): 168.7
 168.0 cm = 5 feet, 6.4
 inches
 Enter a height in centimeters (<=0 to quit): 0
 bye*/

#include <stdio.h>

int main (void){
    const int INCH_IN_FEET = 12;
    const float INCH_IN_CM = 0.394;

    float height_cm;
    float height_inch;

    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf ("%f", &height_cm);
    while (height_cm > 0){
        height_inch = height_cm * INCH_IN_CM;
        printf("%.1f cm = %d feet, %.1f inches.\n",
        height_cm, (int)(height_inch/INCH_IN_FEET),height_inch - (int)(height_inch/INCH_IN_FEET)*INCH_IN_FEET);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf ("%f", &height_cm);
    }
    printf("Bye!\n");

    return 0;
}