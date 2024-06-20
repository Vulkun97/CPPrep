/*Use nested loops to produce the following pattern: 
 $
 $$
 $$$
 $$$$
 $$$$$ */

#include <stdio.h>

int main(void){
    for (int i = 0; i < 5; i++){
        for(int k = 0; k <= i; k++)
            printf("$");
        printf("\n");
    }

    return 0;
}