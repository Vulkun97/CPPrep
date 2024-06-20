/*Write a file-copy program that takes the original filename and the copy file from the 
command line. Use standard I/O and the binary mode, if possible. */

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

    orig_fp = fopen(argv[1], "rb");
    copy_fp = fopen(argv[2], "wb");

    if(orig_fp == NULL || copy_fp == NULL){
        printf("Cant open file(s)");
        return 2;
    }

    while(1){
        read = fread(buffer, sizeof(char), SIZE, orig_fp);
        fwrite(buffer, sizeof(char), read, copy_fp);
        if (read < SIZE)
            break;
    }
    

    fclose(orig_fp);
    fclose(copy_fp);
    printf("Done");
    return 0;

}