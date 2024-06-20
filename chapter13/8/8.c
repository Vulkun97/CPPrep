/*Write a program that takes as command-line arguments a character and zero or more 
filenames. If no arguments follow the character, have the program read the standard 
input. Otherwise, have it open each file in turn and report how many times the character 
appears in each file. The filename and the character itself should be reported along with 
the count. Include error-checking to see whether the number of arguments is correct and 
whether the files can be opened. If a file can’t be opened, have the program report that 
fact and go on to the next file. */


#include <stdio.h>

int ch_count(FILE*, char);

int main(int argc, char* argv[]){
    FILE* fp = stdin;

    if(argc < 2){
        printf("Usage: programm char file1 file2 ... filen");
        return 1;
    }

    if(argc == 2){
        printf("Character %c appears in your input %d times!\n",
        argv[1][0], ch_count(fp, argv[1][0]));
        return 0;
    }

    for(int i = 2; i < argc; i++){
        FILE* fp = fopen (argv[i], "r");
        if (fp == NULL){
            printf(" Cant open %s\n", argv[i]);
            continue;
        }

        printf("Character %c appears in %s %d times!\n",
        argv[1][0], argv[i], ch_count(fp, argv[1][0]));
    }

    return 0;
}

int ch_count(FILE* fp, char ch){
    char read_ch;
    int count = 0;

    while((read_ch = getc(fp)) != EOF){
        if (read_ch == ch){
            count++;
        }
    }

    return count;
}