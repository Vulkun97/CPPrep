/*Write a program that reads input up to # and reports the number of times that the 
sequence ei occurs.*/

#include <stdio.h>
#define STOP_CH '#'

int main (void){
    char input;
    char p_input = 0;
    int sec_count = 0;

    printf("Enter characters (%c to stop): ", STOP_CH);
    while ((input = getchar()) != STOP_CH){
        if (input == 'i' && p_input == 'e')
            sec_count++;
        p_input = input;
    }

    printf("Sequence occured %d times", sec_count);
    return 0;
}