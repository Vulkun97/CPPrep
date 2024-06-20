/* Write a program that reads input until encountering the # character and then reports 
the number of spaces read, the number of newline characters read, and the number of all 
other characters read. */

#include <stdio.h>
#include <string.h>

#define STOP_CH '#'

int main (void){
    char input;
    int space_num = 0, null_num = 0, other_num = 0;

    printf("Enter characters (%c to stop):", STOP_CH);

    while ((input = getchar()) != STOP_CH){
        if (input == ' ')
            space_num++;
        else if (input == '\n')
            null_num++;
        else
            other_num++;
    }
    
    printf("You entered %d spaces, %d newline characters and %d other characters!",
    space_num, null_num, other_num);
    return 0;
}