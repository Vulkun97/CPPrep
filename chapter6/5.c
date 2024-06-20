/*Have a program request the user to enter an uppercase letter. Use nested loops to produce 
a pyramid pattern like this: 
 A
 ABA
 ABCBA
 ABCDCBA
 ABCDEDCBA 
The pattern should extend to the character entered. For example, the preceding pattern 
would result from an input value of E. Hint: Use an outer loop to handle the rows. Use 
three inner loops in a row, one to handle the spaces, one for printing letters in ascending 
order, and one for printing letters in descending order. I*/

#include <stdio.h>

int main(void){
    char letter;
    int depth;

    do {
        printf("Enter an uppercase letter: ");
        scanf("%c", &letter);
        getchar();
    } while ( letter < 'A' || letter > 'Z');



    depth = letter - 'A';


    for (int i = 0; i <= depth; i++){
        for(int k = 0; k < depth - i; k++)
            printf(" ");

        for(char ch = 'A'; ch <= 'A' + i; ch++)
            printf("%c", ch);

        for(char ch1 = 'A'- 1 + i; ch1 >= 'A'; ch1--)
            printf("%c", ch1);

        printf("\n");
    }

    return 0;
}