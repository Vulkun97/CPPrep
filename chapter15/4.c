/*Write a function that takes two int arguments: a value and a bit position. Have the 
function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test 
the function in a program. */

#include <stdio.h>
#include <string.h>


int bit_mask(int, int);

int main(void){
    printf("%d\n", bit_mask(14029, 5));
    printf("%d\n", bit_mask(252, 3));
    printf("%d\n", bit_mask(75522, 8));
}

int bit_mask(int number, int position){
    return (number >> position) & 1;
}