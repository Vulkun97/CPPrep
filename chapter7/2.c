/*Write a program that reads input until encountering #. Have the program print each 
input character and its ASCII decimal code. Print eight character-code pairs per line. 
Suggestion: Use a character count and the modulus operator ( %) to print a newline 
character for every eight cycles of the loop. */

#include <stdio.h>
#include <string.h>

#define STOP_CH '#'
#define MAX_CH 200

int main (void){
    char input;
    int ch_count = 0;
    char input_array [MAX_CH];

    printf("Enter maximum %d characters (%c to stop):", MAX_CH, STOP_CH);

    while ((input = getchar()) != STOP_CH && ch_count < MAX_CH){
        input_array[ch_count++] = input;
    }

    for (int i = 1; i <= ch_count; i++){
        printf("%c %4d   ", input_array[i - 1], input_array[i - 1]);
        if (i % 8 == 0)
            printf("\n");
    }
    
    return 0;
}