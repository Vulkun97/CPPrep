/*Write a program that reads integers until 0 is entered. After input terminates, the 
program should report the total number of even integers (excluding the 0) entered, the 
average value of the even integers, the total number of odd integers entered, and the 
average value of the odd integers. */

#include <stdio.h>

int main (void){
    int input, even_count = 0, odd_count = 0, average_even = 0, average_odd = 0;

    printf("Enter integers (enter 0 to quit):");
    scanf("%d", &input);
    while (input != 0){
        if (input%2){
         odd_count++;
            average_odd += input;
        }
        else{
            even_count++;
            average_even += input;
        }

        printf("Enter integers (enter 0 to quit):");
        scanf("%d", &input);
    }

    average_odd /= odd_count;
    average_even /= even_count;

    printf("You entered %d even integers with average of %d.\n", even_count, average_even);
    printf("And you entered %d odd integers with average of %d.", odd_count, average_odd);

    return 0;
}