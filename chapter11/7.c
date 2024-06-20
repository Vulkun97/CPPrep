/*The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating 
s2 or padding it with extra null characters as necessary. The target string may not be 
null-terminated if the length of s2 is n or more. The function returns s1. Write your own 
version of this function; call it mystrncpy(). Test the function in a complete program 
that uses a loop to provide input values for feeding to the function.*/

//сделаю, которая всегда возвращает s1 с символом окончания строки 

#include <stdio.h>
#define SIZE 21

char* mystrcpy(char*,const char*, int);

void read(char*, int);

int main(void){
    char str1[SIZE];
    char str2[SIZE];

    printf("Enter a string of %d characters max: ", SIZE - 1);

    read(str2, SIZE - 1);

    mystrcpy(str1, str2, 5);

    printf("Copy of string is: %s", str1);

    return 0;
}

char* mystrcpy(char* str1, const char* str2, int size){
    int i;
    for (i = 0; i < size; i++){
        *(str1+i) = *(str2+i);
        if (*(str2+i) == '\0')
            break;
    }

    *(str1+i) = '\0';

    return str1;
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