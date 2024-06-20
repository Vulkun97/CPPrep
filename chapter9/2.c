/*Devise a function chline(ch,i,j) that prints the requested character in columns i
through j. Test it in a simple driver.*/

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