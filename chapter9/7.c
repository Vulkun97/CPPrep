/*Write a program that reads characters from the standard input to end-of-file. For each 
character, have the program report whether it is a letter. If it is a letter, also report 
its numerical location in the alphabet. For example, c and C would both be letter 3. 
Incorporate a function that takes a character as an argument and returns the numerical 
location if the character is a letter and that returns –1 otherwise. */

#include <stdio.h>
#include <ctype.h>

int alpha_location (char);

int main(void){
    char ch;
    int location = 0;

    printf("Enter a string of letters (EOF to quit): \n");

    while ((ch = getchar()) != EOF){
        if (location = alpha_location(ch)){
            printf("Char %c is %d letter in the alphabet\n", ch, location);
        }
        else {
            printf("Char %c is not a letter\n", ch);
        }
        location = 0;
    }

    printf("Done");
    return 0;

}


int alpha_location (char ch){
    if (isalpha(ch)){
        return toupper(ch) - 64;
    }
    return 0;
}