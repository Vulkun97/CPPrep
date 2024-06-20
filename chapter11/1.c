/*Design and test a function that fetches the next n characters from input (including 
blanks, tabs, and newlines), storing the results in an array whose address is passed as an 
argument. */

#include <stdio.h>

#define SIZE 21

void read(char*, int);

int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    read(str, SIZE - 10);

    printf("Read: %s\n", str);
    return 0;
}

void read(char* str, int size){
    int i;
    for(i = 0; i <= size; i++){
        str[i] = getchar();
    }
    while(getchar() != '\n' && str[i] != '\n')
        continue;
    str[i] = '\0';
}