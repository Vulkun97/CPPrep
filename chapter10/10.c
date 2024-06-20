/*Write a function that sets each element in an array to the sum of the corresponding 
elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2 
has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The 
function should take three array names and an array size as arguments. Test the function 
in a simple program. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void db_populate(double* , int);
void copy_arr(double[], double[], int);
void arr_sum(double* target, double* source1, double* source2, int size);

int main(void){
    double arr1[SIZE];
    double arr2[SIZE];
    double arr3[SIZE];
    

    srand(time(NULL)); //генерация сида по времени

    //заполняем массивы
    db_populate(arr1, SIZE);
    printf("+\n");
    db_populate(arr2, SIZE);
    //db_populate(arr3, SIZE);

    arr_sum(arr3, arr1, arr2, SIZE);

    printf("=\n");

    for(int i = 0; i < SIZE; i++){
        printf("%6.2lf ", arr3[i]);
    }
}

void copy_arr(double target[], double source[], int size){
    for(int i = 0; i < size; i++)
        target[i] = source[i];
}

void db_populate(double* arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = ((double)rand())/rand();
        printf("%6.2lf ", arr[i]);
    }
    printf("\n");
}

void arr_sum(double* target, double* source1, double* source2, int size){
    for(int i = 0; i < size; i++)
        *(target + i) = *(source1 + i) + *(source2 + i);
}