/*Write a function that returns the largest value stored in an array-of- int. Test the function 
in a simple program. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


int largest (int*, int);

int main(void){
    int arr[SIZE];
    int num;

    srand(time(NULL)); //генерация сида по времени

    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
        printf("%d ", arr[i]);
    }

    printf("\n");

    num = largest(arr, SIZE);

    printf("largest is %d", num);

    return 0;
}

int largest(int* arr, int size){
    int largest = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] > largest)
            largest = arr[i];
    }

    return largest;
}