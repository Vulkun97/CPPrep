/*Write a function that replaces the contents of a string with the string reversed. Test the 
function in a complete program that uses a loop to provide input values for feeding to 
the function.*/

#include <stdio.h>
#define SIZE 21

void read(char*, int);

void reverse(char[]);

int main(void){
    char str1[SIZE];

    printf("Enter a string of %d characters max: ", SIZE - 1);
    read(str1, SIZE - 1);

    reverse(str1);

    printf("Your string reversed is %s", str1);

    return 0;
}

void reverse(char str[]){
    char temp;
    int length = 0;

    while (str[length++] != '\0')
        continue;

    for (int i = 0; i < length/2; i++){
        temp = str[i];
        str[i] = str[length - i - 2];
        str[length - i - 2] = temp;
    }
}

void read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if(str[i] == '\n')
            break;
    }
    if(i == size)
        while(getchar() != '\n')
            continue;
    
    str[i] = '\0';
}