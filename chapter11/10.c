/*Write a function that takes a string as an argument and removes the spaces from the 
string. Test it in a program that uses a loop to read lines until you enter an empty line. 
The program should apply the function to each input string and display the result. */

#include <stdio.h>
#define SIZE 21

void read(char*, int);

void rem_sp(char[]);

int main(void){
    char str1[SIZE];

    printf("Enter a string of %d characters max: ", SIZE - 1);
    read(str1, SIZE - 1);

    rem_sp(str1);

    printf("Your string without spaces is %s", str1);

    return 0;
}

void rem_sp(char str[]){
    int i = 0;
    int k;
    int length = 0;
    int count = 0;

    while (str[length++] != '\0')
        continue;

    while (str[i] != '\0'){
        if (str[i] == ' '){
            for (k = i; k < length - 1; k++){
                str[k] = str[k+1];
            }
        }
        i++;
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