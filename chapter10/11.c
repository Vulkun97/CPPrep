/*Write a program that declares a 3×5 array of int and initializes it to some values of 
your choice. Have the program print the values, double all the values, and then display 
the new values. Write a function to do the displaying and a second function to do the 
doubling. Have the functions take the array name and the number of rows as arguments. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE1 5
#define SIZE2 20

void td_int_populate(int arr[][SIZE2], int rows);
void td_int_display(int arr[][SIZE2], int rows);
void td_int_double(int arr[][SIZE2], int rows);

int main(void){
    int arr1[SIZE1][SIZE2];
    
    srand(time(NULL)); //генерация сида по времени
    //заполнение массива
    td_int_populate(arr1, SIZE1);

    td_int_display(arr1, SIZE1);
    printf("\n");

    td_int_double(arr1, SIZE1);

    td_int_display(arr1, SIZE1);
}

void td_int_populate(int arr[][SIZE2], int rows){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < SIZE2; k++){
            arr[i][k] = rand();
        }
    }

}

void td_int_display(int arr[][SIZE2], int rows){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < SIZE2; k++){
            printf("%8d", arr[i][k]);
        }
        printf("\n");
    }
}

void td_int_double(int arr[][SIZE2], int rows){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < SIZE2; k++){
            arr[i][k] *= 2;
        }
    }
}