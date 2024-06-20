/*Design and test a function like that described in Programming Exercise 3 except that it 
accepts a second parameter specifying the maximum number of characters that can be 
read.*/

#include <stdio.h>
#define SIZE 21

void read(char [], int);

int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    read(str, SIZE - 10);

    printf("Read: %s\n", str);
    return 0;
}


void read(char str[], int size){
    char ch;
    while ((ch = getchar()) == ' ')
        continue;
    str[0] = ch;
    for (int i = 1; i < size - 1; i++){
        ch = getchar();
        if (ch == ' ' || ch == '\t' || ch == '\n')
            break;
        str[i] = ch;
    }
}