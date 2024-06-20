/*Redo exercise 4 using a switch .*/

#include <stdio.h>

#include <stdio.h>
#include <string.h>

#define STOP_CH '#'
#define MAX_CH 200

int main (void){
    char input;
    int ch_count = 0;
    char input_array [MAX_CH];
    int subs_count = 0;

    printf("Enter maximum %d characters (%c to stop):", MAX_CH, STOP_CH);

    while ((input = getchar()) != STOP_CH && ch_count < MAX_CH){
        switch (input) {
            case '.':   input_array[ch_count] = '!';
                        subs_count++;
                        break;
            case '!':
                        input_array[ch_count] = '!';
                        input_array[++ch_count] = '!';//потенциальная ошибка, если чар_каунт был 199, то тут он станет 200
                        subs_count++;
                        break;
            default:
                        input_array[ch_count] = input;
        }
        ch_count++;
    }

    for (int i = 0; i < ch_count; i++){
        printf("%c", input_array[i]);
    }

    printf("\nThere was %d substitutions", subs_count);
    return 0;
}