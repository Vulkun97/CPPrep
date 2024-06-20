/*Write a program that initializes a two-dimensional array-of- double and uses one of the 
copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a 
two-dimensional array is an array of arrays, a one-dimensional copy function can be used 
with each subarray.)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5


void copy_arr(double[], double[], int);

int main(void){
    double arr1[SIZE][SIZE];
    double arr2[SIZE][SIZE];
    double num;


    srand(time(NULL)); //генерация сида по времени

    //заполняем массив
    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            arr1[i][k] = ((double)rand())/rand();
            printf("%5.2lf ", arr1[i][k]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++){
        copy_arr(arr2[i], arr1[i], SIZE);
    }

    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            printf("%5.2lf ", arr2[i][k]);
        }
        printf("\n");
    }
    
    
}

void copy_arr(double target[], double source[], int size){
    for(int i = 0; i < size; i++)
        target[i] = source[i];
}