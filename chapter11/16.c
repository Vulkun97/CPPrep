/*
Write a program that reads input until end-of-file and echoes it to the display. Have the 
program recognize and implement the following command-line arguments: 

-p Print input as is 
-u Map input to all uppercase 
-l Map input to all lowercase 

Also, if there are no command-line arguments, let the program behave as if the –p
argument had been used.
*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 21

int read(char*, int);

void strupper(char[], int);

void strlower(char[], int);

int main(int argc, char* argv[]){
    if(argc > 2){
        printf("Incorrect arg ammount!");
        return 1;
    }

    char str[SIZE];

    printf("Enter a string max %d char long: ", SIZE);
    read(str, SIZE);

    if (argv[1][1] == 'u'){
        strupper(str, SIZE);
        printf("Your string in upper case:\n");
        printf("%s", str);
    }
    else if (argv[1][1] == 'l'){
        strlower(str, SIZE);
        printf("Your string in lower case:\n");
        printf("%s", str);
    }
    else {
        printf("Your string as it is:\n");
        printf("%s", str);
    }

    return 0;
}

int read(char* str, int size){
    for(int i = 0; i < size; i++){
        str[i] = getchar();
        if (str[i] == '\n'){
            str[i] = '\0';
            return 1;
        }
        if (str[i] == EOF){
            str[i] = '\0';
            return EOF;
        }
    }

    while(getchar() != '\n')
        continue;

    return 2;
}

void strupper(char str[], int size){
    for(int i = 0; i < size; i++){
        str[i] = toupper(str[i]);
    }
}

void strlower(char str[], int size){
    for(int i = 0; i < size; i++){
        str[i] = tolower(str[i]);
    }
}