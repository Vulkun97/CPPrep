/*Write a program that reads eight integers into an array and then prints them in reverse 
order. */

#include <stdio.h>
#define MAX_SIZE 8

int main (void){
    int numbers[MAX_SIZE];

    printf("Enter %d integers: ", MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
        scanf("%d", &numbers[i]);
    
    printf ("Reverse order is: \n");

    for (int i = MAX_SIZE - 1; i >= 0; i--)
        printf("%d ", numbers[i]);

    return 0;
}