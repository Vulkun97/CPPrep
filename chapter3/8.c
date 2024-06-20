/*In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an 
ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a 
volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons, 
and teaspoons. Why does a floating-point type make more sense for this application than 
an integer type? 
*/

#include <stdio.h>

int main (void){
    float cups;

    printf ("Enter volume in cups: ");
    scanf("%f", &cups);
    printf ("There is %f pints in %f cups.\n", cups/2, cups);
    printf ("There is %f ounces in %f cups.\n", cups * 8, cups);
    printf ("There is %f tablespoons in %f cups.\n", cups * 8 * 2, cups);
    printf ("There is %f teaspoons in %f cups.\n", cups * 8 * 2 * 3, cups);
}