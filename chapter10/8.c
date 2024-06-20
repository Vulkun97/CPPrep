/*Use a copy function from Programming Exercise 2 to copy the third through fifth 
elements of a seven-element array into a three-element array. The function itself need 
not be altered; just choose the right actual arguments. (The actual arguments need not be 
an array name and array size. They only have to be the address of an array element and a 
number of elements to be processed.)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


void copy_arr(double[], double[], int);

int main(void){
    double arr1[SIZE];
    double num;
    double arr2[3];

    srand(time(NULL)); //генерация сида по времени

    //заполняем массив
    for(int i = 0; i < SIZE; i++){
        arr1[i] = ((double)rand())/rand();
        printf("%5.2lf ", arr1[i]);
    }
    printf("\n");

    copy_arr(arr2, arr1+2, 3);

    for(int i = 0; i < 3; i++){
        printf("%5.2lf ", arr2[i]);
    }
}

void copy_arr(double target[], double source[], int size){
    for(int i = 0; i < size; i++)
        target[i] = source[i];
}