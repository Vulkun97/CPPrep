/*Write a program that lets you input a string. The program then should push the 
characters of the string onto a stack, one by one (see review question 5), and then pop 
the characters from the stack and display them. This results in displaying the string in 
reverse order.*/

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define SIZE 40

char * s_gets(char * st, int n);

void showChar(Item item);

int main(void){
    Stack stack;
    char input[SIZE];
    unsigned int index;
    Item temp;

    printf("Enter the string:\n");

    while (s_gets(input, SIZE) != NULL && input[0] != '\0'){
        InitializeStack(&stack);

        index = 0;

        while((temp.character = input[index++]) != '\0'){
            EnStack(temp, &stack);
        }

        
        printf("String characters in reverse order:\n");

        TraverseStack(&stack, showChar);

        EmptyTheStack(&stack);

        printf("\nEnter new string:\n");
    }
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);

    if (ret_val){
        find = strchr(st, '\n'); // look for newline
    if (find) // if the address is not NULL,
        *find = '\0'; // place a null character there
    else
        while (getchar() != '\n')
            continue; // dispose of rest of line
    }

    return ret_val;
}

void showChar(Item item){
    printf("%c", item.character);
}