/*Write a function called is_within() that takes a character and a string pointer as its two 
function parameters. Have the function return a nonzero value (true) if the character is 
in the string and zero (false) otherwise. Test the function in a complete program that uses 
a loop to provide input values for feeding to the function. */

#include <stdio.h>
#define SIZE 21

int is_within(const char*, char);

char* search(const char*, char);

void read(char*, int);

int main(void){
    char str[SIZE];
    char ch;
    char* ptr = NULL;
    int answer;

    while(1){
        printf("Enter a string (%d characters max):\n", SIZE - 1);
        read(str, SIZE - 1);
        printf("Enter a char to find: \n");
        ch = getchar();
        getchar();


        if (!is_within(str, ch)){
            printf("There is no such character in the string!\n");
        }
        else{
            printf("Found char \'%c\' in the string!\n", ch);
        }

        printf("Continue? (n for no): ");
        ch = getchar();
        getchar();

        if(ch == 'n')
            break;
    }
    
    printf("Done");
    return 0;
}

int is_within(const char* str, char ch){
    int answer;
    do {
        answer = *str;
        str++;
    }
    while (answer != '\0' && answer != ch);

    return answer;
}

char* search(const char* str, char ch){
    char* ptr = NULL;

    while (*str != ch && *str != '\0')
        str++;

    if (*str == ch)
        ptr = (char*) str;

    return ptr;
}

void read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if(str[i] == '\n')
            break;
    }
    while(getchar() != '\n' && str[i] != '\n')
        continue;
    str[i] = '\0';
}