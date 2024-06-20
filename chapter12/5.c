#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MIN 1
#define MAX 10

void intsort(int[], int);

int main(void){
    int numbers[SIZE];

    srand((unsigned int)time(0));
    for (int i = 0; i < SIZE; i++){
        numbers[i] = rand() % (MAX - MIN + 1) + MIN;
    }

    intsort(numbers, SIZE);

    printf("Array sorted: \n");
    for (int i = 0; i < SIZE; i++){
        printf("Element %2d: %2d\n", i, numbers[i]);
    }

    printf("Done");
    return 0;
}

void intsort(int arr[], int size){
    int swap = 1;
    int temp;

    while(swap){
        swap = 0;
        for (int i = 0; i < size - 1; i++){
            if(arr[i] < arr[i+1]){
                swap = 1;

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}