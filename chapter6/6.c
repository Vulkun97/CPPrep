/*Write a program that prints a table with each line giving an integer, its square, and its 
cube. Ask the user to input the lower and upper limits for the table. Use a for loop. */

#include <stdio.h>

int main(void){
    int upper = 0;
    int lower = 0;

    do {
        printf("Enter lower and upper limit: ");
        scanf("%d %d", &lower, &upper);
    }while ( upper < lower);

    for (int i = lower; i <= upper; i++){
        printf("%10d  %10d  %10d", i, i*i, i*i*i);
        printf("\n");
    }


    return 0;
}