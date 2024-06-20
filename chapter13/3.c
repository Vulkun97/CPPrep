/*Write a file copy program that prompts the user to enter the name of a text file to act as 
the source file and the name of an output file. The program should use the toupper()
function from ctype.h to convert all text to uppercase as it’s written to the output file. 
Use standard I/O and the text mode. */

#include <stdio.h>
#define SIZE 64

int main(int argc, char* argv[]){
    FILE* orig_fp;
    FILE* copy_fp;
    char buffer[SIZE];
    size_t read;

    if(argc != 3){
        printf("Usage: program orig_file copy_file");
        return 1;
    }

    orig_fp = fopen(argv[1], "r");
    copy_fp = fopen(argv[2], "w");

    if(orig_fp == NULL || copy_fp == NULL){
        printf("Cant open file(s)");
        return 2;
    }

    while(fgets(buffer, SIZE, orig_fp) != NULL){
        fputs(buffer, copy_fp);
    }
    

    fclose(orig_fp);
    fclose(copy_fp);
    printf("Done");
    return 0;

}