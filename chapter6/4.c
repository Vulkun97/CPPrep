/*Use nested loops to produce the following pattern: 
 A
 BC
 DEF
 GHIJ
 KLMNO
 PQRSTU*/
 
#include <stdio.h>

int main(void){
    char ch = 'A';
    for(int i = 0; i < 6; i++){
        for(int n = 0; n <= i; ch++, n++)
            printf("%c", ch);

        printf("\n");
    }

    return 0;
}