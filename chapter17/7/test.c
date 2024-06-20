/* Write a program that opens and reads a text file and records how many times each word 
occurs in the file. Use a binary search tree modified to store both a word and the number 
of times it occurs. After the program has read the file, it should offer a menu with three 
choices. The first is to list all the words along with the number of occurrences. The 
second is to let you enter a word, with the program reporting how many times the word 
occurred in the file. The third choice is to quit.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAXWORD 40

int get_word(char buffer[],FILE *fp, int size);

char * s_gets(char * st, int n);

void uppercase(char * str);

int main(int argc, char* argv[]){
    FILE* fp;
    char buffer[MAXWORD];
    char choice;
    int get_word_return = 0;

    if(argc != 2){
        printf("Usage: program file");
        printf("%d", argc);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Cant open file");
        return 2;
    }


    while(get_word_return != EOF){
        get_word_return = get_word(buffer, fp, MAXWORD);
        uppercase(buffer);
        printf("%s\n", buffer);
    }

     fclose(fp);
     printf("Done");
     return 0;
}

int get_word(char buffer[],FILE *fp, int size){///////////////////////
    static int in_word = 0;
    char read_char;
    int index = 0;
    char past_char = 0;

    do{
        read_char = getc(fp);

        if(isalnum(past_char)){
            in_word = 1;
            buffer[index++] = past_char;
        }
        
        if (in_word && ispunct(past_char) && isalnum(read_char)){
            buffer[index++] = past_char;
        }

        if(in_word && isspace(read_char) || index >= size - 1){
            buffer[index] = '\0';
            in_word = 0;
            return 0;
        }

        past_char = read_char;

    }while(read_char != EOF);

    buffer[index] = '\0';
    return EOF;
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

void uppercase(char * str){
    while (*str){
        *str = toupper(*str);
        str++;
    }
}