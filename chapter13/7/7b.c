/*Write a program that opens two files. You can obtain the filenames either by using 
command-line arguments or by soliciting the user to enter them.
 a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the 
first file, line 2 of the second file, and so on, until the last line of the longer file (in 
terms of lines) is printed.
 b. Modify the program so that lines with the same line number are printed on the 
same line.*/

#include <stdio.h>

int read_line (FILE*);

int main(){
    FILE* fp1;
    FILE* fp2;
    int fp1_chek = 1;
    int fp2_chek = 1;
    char filename1[30] = "a.txt";
    char filename2[30] = "b.txt";

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    if (fp1 == NULL || fp2 == NULL){
        printf("Cant open files");
        return 2;
    }

    while(1){
        fp1_chek = read_line(fp1);
        fp2_chek = read_line(fp2);
        printf("\n");
        if (fp1_chek == 1 && fp2_chek == 1)
            break;
    }

    printf("\nDone");
    return 0;
}

int read_line (FILE* fp){
    char ch;

    while (1){
        ch = getc(fp);
        if (ch == EOF){
            return 1;
        }
        if (ch == '\n')
            break;
        putc(ch, stdout);
        
    }

    return 0;
}