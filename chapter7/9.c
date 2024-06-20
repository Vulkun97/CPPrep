/*Write a program that accepts a positive integer as input and then displays all the prime 
numbers smaller than or equal to that number.*/

#include <stdio.h>

int isPrime (unsigned int n);

int main (void){
    unsigned int number;

    printf("Enter positive integer: ");
    scanf("%u", &number);

    printf("Prime numbers in this integer: \n");
    for (int i = 1; i <= number; i++){
        if (isPrime(i)){
            printf("%d\n", i);
        }
    }

    return 0;

}

int isPrime (unsigned int n){
        for (int i = 2; i <= n/2; i++){
            if (n % i == 0)
            return 0;
        }
    return 1;
}