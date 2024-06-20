/*Design and test a function that reads the first word from a line of input into an array and 
discards the rest of the line. It should skip over leading whitespace. Define a word as a 
sequence of characters with no blanks, tabs, or newlines in it. Use getchar().*/

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