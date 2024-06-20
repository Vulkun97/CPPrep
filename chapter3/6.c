/*The mass of a single molecule of water is about 3.0×10 -23 grams. A quart of water is 
about 950 grams. Write a program that requests an amount of water, in quarts, and 
displays the number of water molecules in that amount.*/

#include <stdio.h>

int main (void){
    float amount;

    printf("Enter amount of water in quarts: ");
    scanf ("%f", &amount);
    printf("That volume approximately contains %f molecules of water", amount * 950 / 3e-23);

    return 0;
}