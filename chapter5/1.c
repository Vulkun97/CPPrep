/*Write a program that converts time in minutes to time in hours and minutes. Use 
#define or const to create a symbolic constant for 60. Use a while loop to allow the 
user to enter values repeatedly and terminate the loop if a value for the time of 0 or less 
is entered. */

#include <stdio.h>
#include <string.h>

int main (void){
    const int M_H = 60;

    int minutes;
    int hours;
    printf("Enter time in minutes (enter 0 to quit): ");
    scanf("%d", &minutes);
    while(minutes > 0){
        hours = minutes / M_H;
        minutes = minutes % M_H;
        printf("Thats %d hours and %d minutes.\n", hours, minutes);
        printf("Enter time in minutes (enter 0 to quit): ");
        scanf("%d", &minutes);
    }
    printf("Bye!");
}