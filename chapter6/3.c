/*Use nested loops to produce the following pattern: 
 F
 FE
 FED
 FEDC
 FEDCB
 FEDCBA */

#include <stdio.h>

int main (void){
    for (char ch1 = 'F'; ch1 >= 'A'; ch1--){
        for(char ch2 = 'F'; ch2 >= ch1; ch2--)
            printf("%c", ch2);
        printf("\n");
    }

    return 0;
}