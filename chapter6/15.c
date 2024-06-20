/*Write a program that reads in a line of input and then prints the line in reverse order. 
You can store the input in an array of char; assume that the line is no longer than 255 
characters. Recall that you can use scanf() with the %c specifier to read a character at 
a time from input and that the newline character ( \n) is generated when you press the 
Enter key. */

#include <stdio.h>
#define SIZE 256

int main (void){
    char text[SIZE];
    int k = 0;

    printf("Enter a line of text: ");

    do {
        scanf("%c", &text[k]);
    } while (text[k++] != '\n' && k < SIZE);

    for (int i = k - 2; i >= 0; i--){
        printf("%c", text[i]);
    }

    return 0;
}