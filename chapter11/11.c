/*Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it 
offer the user a menu with five choices: print the original list of strings, print the strings in ASCII collating sequence, print the strings in order of increasing length, print the 
strings in order of the length of the first word in the string, and quit. Have the menu 
recycle until the user enters the quit request. The program, of course, should actually 
perform the promised tasks. */

#include <stdio.h>
#include <string.h>
#define S_SIZE 11
#define A_SIZE 10

int read(char*, int);

void lensort(char[][S_SIZE], int);

int wordlen (const char[]);

void wordsort(char[][S_SIZE], int);

int main(void){
    int strcnt = 0;
    int choice = 10;
    char strarr[A_SIZE][S_SIZE];

    for(strcnt = 0; strcnt < A_SIZE; strcnt++){
        printf("Enter string number %d: ", strcnt+1);
        if ((read(strarr[strcnt], S_SIZE-1)) == EOF)
            break;
    }

    while(choice != 5){
        choice = 10;
        printf("What do you want to do with the strings?\n");
        printf("1) print the original list of strings\n");
        printf("2) print the strings in ASCII collating sequence\n");
        printf("3) print the strings in order of increasing length\n");
        printf("4) print the strings in order of the length of the first word in the string\n");
        printf("5) quit\n");
        printf("Enter number of the option: ");
        scanf("%d", &choice);

        switch(choice){
            case(1):
                printf("Original strings:\n");
                for(int i = 0; i < strcnt; i++){
                    printf("%2d: ", i+1);
                    printf("%s\n", strarr[i]);
                }
                break;
            case(2):
                printf("Strings in ASCII:\n");
                for(int i = 0; i < strcnt; i++){
                    printf("%2d: ", i+1);
                    int strlength = strlen(strarr[i]);
                    for(int k = 0; k < strlength; k++)
                        printf("%3d ", strarr[i][k]);
                    printf("\n");
                }
                    
                break;
            case(3):
                printf("Strings in order of increasing length:\n");
                lensort(strarr, strcnt);
                
                for(int i = 0; i < strcnt; i++){
                    printf("%2d: ", i+1);
                    printf("%s\n", strarr[i]);
                }
                    
                break;
            case(4):
                printf("Strings in order of the length of the first word:\n");
                wordsort(strarr, strcnt);
                
                for(int i = 0; i < strcnt; i++){
                    printf("%2d: ", i+1);
                    printf("%s\n", strarr[i]);
                }

                break;
        }
    }

    printf("Done");
    return 0;
}

int read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if (str[i] == '\n')
            goto read_end;
        if (str[i] == EOF)
            return EOF;
    }

    while(getchar() != '\n')
        continue;

    read_end:
        str[i] = '\0';
        return 1;
}

void lensort(char strarr[][S_SIZE], int size){
    char temp[S_SIZE];
    int templen;
    int length[size];
    int swap = 1;

    for (int i = 0; i < size; i++)
        length[i] = strlen(strarr[i]);

    while(swap){
        swap = 0;
        for (int i = 0; i < size - 1; i++){
            if(length[i] > length[i+1]){
                swap = 1;

                templen = length[i];
                length[i] = length[i+1];
                length[i+1] = templen;

                strcpy(temp, strarr[i]);
                strcpy(strarr[i], strarr[i+1]);
                strcpy(strarr[i+1], temp);
            }
        }
    }
}

int wordlen (const char str[]){
    int index = 0;
    int length = 0;
    while(str[index++] == ' ')
        continue;
    
    while(str[index + length - 1] != ' ' && str[index + length - 1] != '\0')
        length++;
    

    return length;
}

void wordsort(char strarr[][S_SIZE], int size){
    char temp[S_SIZE];
    int templen;
    int length[size];
    int swap = 1;

    for (int i = 0; i < size; i++)
        length[i] = wordlen(strarr[i]);

    while(swap){
        swap = 0;
        for (int i = 0; i < size - 1; i++){
            if(length[i] > length[i+1]){
                swap = 1;

                templen = length[i];
                length[i] = length[i+1];
                length[i+1] = templen;

                strcpy(temp, strarr[i]);
                strcpy(strarr[i], strarr[i+1]);
                strcpy(strarr[i+1], temp);
            }
        }
    }
}