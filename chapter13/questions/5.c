#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 256

int main(int argc, char* argv[]){
    char ch;
    char str[SIZE];
    FILE* fp;

    if(argc != 3 || argv[1][1] != '\0'){
        printf("Use:\n%s *char* *file_name*", argv[0]);
        return 2;
    }

    fp = fopen(argv[2], "r");

    if (fp == NULL){
        printf("File does not exist");
        return 1;
    }

    while(fgets(str, SIZE, fp) != NULL){
        if (strchr(str, argv[1][0]) != NULL)
            printf("%s", str);
    }

    printf("Done");
    return 0;
}