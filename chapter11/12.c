/*Write a program that reads input up to EOF and reports the number of words, the 
number of uppercase letters, the number of lowercase letters, the number of punctuation 
characters, and the number of digits. Use the ctype.h family of functions.*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 301

int read(char*, int);

int count_words (const char*, int);

int count_upper (const char*, int);

int count_lower (const char*, int);

int count_punct (const char*, int);

int count_digit (const char*, int);

int main(void){
    char str[SIZE];
    printf("Enter a string up to %d characters max: ", SIZE - 1);
    read(str, SIZE - 1);
    printf("Your string is:                          %s\n", str);
    printf("Number of words: %d\n", count_words(str, SIZE));
    printf("Number of uppercase letters: %d\n", count_upper(str, SIZE));
    printf("Number of lowercase letters: %d\n", count_lower(str, SIZE));
    printf("Number of punctuation characters: %d\n", count_punct(str, SIZE));
    printf("Number of digits: %d\n", count_digit(str, SIZE));
}

int read(char* str, int size){
    for(int i = 0; i < size; i++){
        str[i] = getchar();
        if (str[i] == '\n'){
            str[i] = '\0';
            return 1;
        }
        if (str[i] == EOF){
            str[i] = '\0';
            return EOF;
        }
    }

    while(getchar() != '\n')
        continue;

    return 2;
}

int count_words (const char* str, int size){
    int count = 0;
    int in_word = 0;

    for(int i = 0; i < size; i++){
        if(!in_word && isalnum(str[i])){
            in_word = 1;
            count++;
        }
        if(in_word && isspace(str[i])){
            in_word = 0;
        }
    }

    return count;
}

int count_upper (const char* str, int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(isupper(str[i]))
            count++;
    }

    return count;
}

int count_lower (const char* str, int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(islower(str[i]))
            count++;
    }

    return count;
}

int count_punct (const char* str, int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(ispunct(str[i]))
            count++;
    }

    return count;
}

int count_digit (const char* str, int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(isdigit(str[i]))
            count++;
    }

    return count;
}