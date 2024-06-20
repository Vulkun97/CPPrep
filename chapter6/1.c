/*Write a program that creates an array with 26 elements and stores the 26 lowercase 
letters in it. Also have it show the array contents.*/

#include <stdio.h>
#define MAX_SIZE 26

int main (void){
    char letters[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++){
        letters[i] = 'a' + i;
        printf("%c", letters[i]);
    }
    return 0;
}