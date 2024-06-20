/*Write a function that returns the index of the largest value stored in an array-of- double . 
Test the function in a simple program.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


int largesti (double*, int);

int main(void){
    double arr[SIZE];
    int num;

    srand(time(NULL)); //генерация сида по времени

    for(int i = 0; i < SIZE; i++){
        arr[i] = ((double)rand())/rand();
        printf("%5.2lf ", arr[i]);
    }

    printf("\n");

    num = largesti(arr, SIZE);

    printf("index of largest is %d", num);

    return 0;
}

int largesti(double* arr, int size){
    double largest = arr[0];
    int index = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > largest){
            largest = arr[i];
            index = i;
        }
    }

    return index;
}