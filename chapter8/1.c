/*Devise a program that counts the number of characters in its input up to the end of file. */

#include <stdio.h>

int main (void){
    int ch;
    int ch_count = 0;

    while ((ch = getchar()) != EOF){
        ch_count++;
    }

    printf("Input has %d characters", ch_count);
    return 0;
}