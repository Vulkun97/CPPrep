/*Write a program that creates an eight-element array of ints and sets the elements to the 
first eight powers of 2 and then prints the values. Use a for loop to set the values, and, 
for variety, use a do while loop to display the values. */

#include <stdio.h>
#include <math.h>

int main (void){
    int power_of_two [8];

    for (int i = 0; i < 8; i++)
        power_of_two[i] = pow(2, i);


    int n = 0;
    do {
        printf("%5d\n", power_of_two[n++]);
    } while (n < 8);

    return 0;
}