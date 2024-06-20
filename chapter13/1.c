/*Modify Listing 13.1so that it solicits the user to enter the filename and reads the user’s 
response instead of using command-line arguments.*/

#include <stdio.h>
#include <stdlib.h> // exit() prototype

#define SIZE 30

int main(int argc, char *argv[]){
    int ch; // place to store each character as read
    FILE *fp; // "file pointer"
    unsigned long count = 0;

    char file[SIZE];

    printf("Enter a file name: ");
    scanf("%s", file);

    if ((fp = fopen(file, "r")) == NULL){
        printf("Can't open %s\n", file); 
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF){
        putc(ch,stdout); // same as putchar(ch);
        count++;
    }

    fclose(fp);

    printf("\nFile %s has %lu characters\n", file, count);
    return 0;
}