/*Write a function that takes an int argument and returns the number of “on” bits in the 
argument. Test the function in a program.*/

#include <stdio.h>
#include <string.h>

int ones_ammount(int);

int main(void){
    int number = 1212;
    printf("%d\n", ones_ammount(number));
    number = 5645;
    printf("%d\n", ones_ammount(number));
    number = 24728;
    printf("%d\n", ones_ammount(number));
}

int ones_ammount(int number){
    int ones_sum = 0;
    while(number){
        ones_sum += (number & 1);
        number >>= 1;
    }
    return ones_sum;
}
