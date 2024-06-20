/*Write a program that asks the user to enter the number of miles traveled and the number 
of gallons of gasoline consumed. It should then calculate and display the miles-per-gallon 
value, showing one place to the right of the decimal. Next, using the fact that one gallon 
is about 3.785 liters and one mile is about 1.609 kilometers, it should convert the mile-per-gallon value to a liters-per-100-km value, the usual European way of expressing fuel 
consumption, and display the result, showing one place to the right of the decimal. Note 
that the U. S. scheme measures the distance traveled per amount of fuel (higher is better), 
whereas the European scheme measures the amount of fuel per distance (lower is better). 
Use symbolic constants (using const or #define) for the two conversion factors.*/

#include <stdio.h>
#include <string.h>

int main (void){
    float km;
    float liters;

    printf("Enter the number of kilometers traveled: ");
    scanf("%f", &km);
    printf("Enter the number of liters of gasoline concumed: ");
    scanf("%f", &liters);
    printf("EU rate is %.1f liters-per-100-km\n"
    "US rate is %.1f miles-per-gallon\n", 100/km*liters, (km/1.609)/(liters/3.785));

    return 0;
}