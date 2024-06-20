/*Write a program that opens a text file whose name is obtained interactively. Set up a 
loop that asks the user to enter a file position. The program then should print the part of 
the file starting at that position and proceed to the next newline character. Let negative 
or nonnumeric input terminate the user-input loop.*/

#include <stdio.h>

#define SIZE 30

int main(void){
    char file_name[SIZE] = "intro.txt";
    char ch;
    FILE* fp;
    long int pos = 50;

    printf("Enter a file name: ");
    scanf("%s", file_name);

    if ((fp = fopen(file_name, "r+")) == NULL){
        printf("Cant open %s", file_name);
        return 1;
    }

    printf("Enter a file position: ");
    while (scanf("%ld", &pos) == 1){
        fseek(fp, pos, SEEK_SET);

        ch = getc(fp);

        while (ch != '\n' && ch != EOF){
            putc(ch, stdout);
            ch = getc(fp);
        }

        printf("\nEnter a newfile position: ");
    }

    printf("Done");
    return 0;
}