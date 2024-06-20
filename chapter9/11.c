/*Write and test a Fibonacci() function that uses a loop instead of recursion to calculate 
Fibonacci numbers.*/

#include <stdio.h>

int fibonacci(int);

int main(void){
    int steps;
    printf("Enter a step for fibonacci number: ");
    scanf("%d", &steps);
    printf("Fibonacci number on that step is %d", fibonacci(steps));
    return 0;
}

int fibonacci(int n){
    int number = 1;
    int past_number = 0;

    for (int i = 0; i < n; i++){
        number += past_number;
        past_number = number - past_number;
    }

    return number;
}