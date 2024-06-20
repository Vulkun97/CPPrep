/*Create a text file consisting of 20 rows of 30 integers. The integers should be in the range 
0–9 and be separated by spaces. The file is a digital representation of a picture, with 
the values 0 through 9 representing increasing levels of darkness. Write a program that 
reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward 
converting this digital representation to a picture, have the program use the values 
in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a 
space character, a 1 value to the period character, and so on, with each larger number 
represented by a character that occupies more space. For example, you might use # to 
represent 9. The last character (the 31st) in each row should be a null character, making 
it an array of 20 strings. Have the program display the resulting picture (that is, print the 
strings) and also store the result in a text file.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

#define ROWS 20
#define CLMS 30



int main(int argc, char* argv[]){
    FILE* source_fp;
    FILE* dist_fp;

    char out_name[SIZE];
    int index = 0;

    int iarr[ROWS][CLMS];
    char sarr[ROWS][CLMS + 1];

    const char grathics[10] = {' ', '.', '\'', ':', '~', '*', '=', '&', '%', '#'};

    if (argc != 2){
        printf("Usage: program file");
        return 1;
    }

    if((source_fp = fopen(argv[1], "r")) == NULL){
        printf("Cant open %s", argv[1]);
        return 2;
    }

    while(isalnum(argv[1][index]) && index < (SIZE - 9)){
        out_name[index] = argv[1][index];
        index++;
    }

    strcat(out_name, "_out.txt");

    if((dist_fp = fopen(out_name, "w")) == NULL){
        printf("Cant create %s", out_name);
        return 3;
    }

    for(int i = 0; i < ROWS; i++){
        for (int k = 0; k < CLMS; k++){
            fscanf(source_fp, "%d", &iarr[i][k]);
        }
    }

    for(int i = 0; i < ROWS; i++){
        for (int k = 0; k < CLMS; k++){
            fprintf(dist_fp, "%c", grathics[iarr[i][k]]);
            fprintf(stdout, "%c", grathics[iarr[i][k]]);
        }
        fprintf(dist_fp, "\n");
        fprintf(stdout, "\n");
    }

    printf("Done");
    return 0;
}