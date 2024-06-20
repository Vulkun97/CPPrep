#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 30

int nextf(FILE* fp, char* str);

int main(int argc, char* argv[]){
    FILE* fp;
    char strf[SIZE];
    float number = 0;
    float count = 0;

    int state;

    fp = (argc > 1 ? fopen(argv[1], "r") : stdin);

    if (fp == NULL){
        printf("File does not exist");
        return 1;
    }

    while(1){
        state = nextf(fp, strf);

        count++;
        number += (float)atof(strf);

        if (state){
            printf("Mean is %.2f", number/ count);
            return 0;
        }
    }
}

int nextf(FILE* fp, char* str){
    int index = 0;
    char ch;

    while ((ch = getc(fp)) != EOF){
        if (isspace(ch))
            break;
        str[index++] = ch;
    }
    str[++index] = '\0';
    
    if (ch == EOF)
        return 1;
    return 0;
}