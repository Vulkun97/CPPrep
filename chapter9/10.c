/*Generalize the to_binary() function of Listing 9.8to a to_base_n() function that 
takes a second argument in the range 2–10. It then should print the number that is its 
first argument to the number base given by the second argument. For example, to_
base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a 
complete program.*/

#include <stdio.h>

void to_base_n(unsigned int, unsigned int);

int main(void){
    unsigned int number;
    unsigned int base;

    printf("Enter integer number and a base (2-10): ");
    scanf("%d %u", &number, &base);
    printf("Number %d in %u base is:\n", number, base);
    to_base_n(number, base);

    return 0;
}

void to_base_n(unsigned int number, unsigned int base){
    if (number >= base)
        to_base_n(number/base, base);
    putchar(number%base + '0');
    return;
}