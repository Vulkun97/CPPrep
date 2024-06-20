/*Write a program that takes two command-line arguments. The first is a string; the 
second is the name of a file. The program should then search the file, printing all lines 
containing the string. Because this task is line oriented rather than character oriented, 
use fgets() instead of getc(). Use the standard C library function strstr() (briefly 
described in exercise 7 of Chapter 11 ) to search each line for the string. Assume no lines 
are longer than 255 characters.*/

#include <stdio.h>
#include <string.h>

#define SIZE 256

int main(int argc, char* argv[]){
    FILE* fp;
    char fstr[SIZE];

    if (argc != 3){
        printf("Usage: program sring file");
        return 1;
    }

    if((fp = fopen(argv[2], "r")) == NULL){
        printf("Cant open %s", argv[2]);
        return 2;
    }

    printf("Strings with \"%s\" in it:\n", argv[1]);

    while(fgets(fstr, SIZE, fp) != NULL){
        if (strstr(fstr, argv[1]) != NULL){
            printf("%s", fstr);
        }
    }

    printf("Done");
    return 0;
}