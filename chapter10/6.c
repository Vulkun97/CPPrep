/*Write a function that reverses the contents of an array of double and test it in a simple 
program.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


void reverse (double*, int);

int main(void){
    double arr[SIZE];
    double num;

    srand(time(NULL)); //генерация сида по времени

    for(int i = 0; i < SIZE; i++){
        arr[i] = ((double)rand())/rand();
        printf("%5.2lf ", arr[i]);
    }

    reverse(arr, SIZE);

    printf("\n");

    for(int i = 0; i < SIZE; i++){
        printf("%5.2lf ", arr[i]);
    }

    return 0;
}

void reverse(double* arr, int size){
    double temp;

    for (int i = 0; i < size/2; i++){
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}