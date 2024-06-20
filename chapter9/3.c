/*Write a function that takes three arguments: a character and two integers. The character 
is to be printed. The first integer specifies the number of times that the character is to 
be printed on a line, and the second integer specifies the number of lines that are to be 
printed. Write a program that makes use of this function.*/

#include <stdio.h>

void chline(char, int, int);

int main(void){
    char ch;
    int columns;
    int rows;

    printf("Enter a character: ");
    ch = getchar();
    getchar();

    printf ("Enter ammount of columns and rows: ");
    scanf("%d %d", &columns, &rows);
    chline(ch, columns, rows);
    return 0;
}

void chline(char ch, int i, int j){
    for (int k = 0; k < i; k++){
        for (int x = 0; x < j; x++){
            printf("%c", ch);
        }

        printf("\n");
    }
}