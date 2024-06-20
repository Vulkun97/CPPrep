/*Write a function that rotates the bits of an unsigned int by a specified number of bits 
to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left, 
and the bits lost from the left end would reappear at the right end. That is, the bit moved 
out of the high-order position is placed in the low-order position. Test the function in a 
program. */

#include <stdio.h>
#include <limits.h>

int rotate_l(int, int);

int main(void){
    printf("%x\n", rotate_l(0xFFFF0000, 5));
    printf("%d\n", rotate_l(252, 3));
    printf("%d\n", rotate_l(75522, 8));
}

int rotate_l(int number, int ammount){
    int mask = 0;

    for(int i = 0; i < ammount - 1; i++){
        mask++;
        mask <<= 1;
    }
    mask++;

    return (number << ammount) | (number >> ((sizeof(int) * CHAR_BIT) - ammount)) & mask;
}