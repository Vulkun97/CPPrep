/*Write a program that reads a single word into a character array and then prints the word 
backward. Hint: Use strlen() ( Chapter 4 ) to compute the index of the last character in 
the array.*/

#include <stdio.h>
#include <string.h>

int main(void){
    char word[20];

    do {
        printf("Enter single word: ");
        
    }while (scanf("%s", word) != 1);

    for (int i = strlen(word) - 1; i >= 0; i--){
        printf("%c", word[i]);
    }

    return 0;
}