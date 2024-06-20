/*Write a program that initializes a two-dimensional 3×5 array-of- double and uses a VLAbased function to copy it to a second two-dimensional array. Also provide a VLA-based 
function to display the contents of the two arrays. The two functions should be capable, 
in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable 
compiler, use the traditional C approach of functions that can process an N×5 array). */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE1 5
#define SIZE2 20

void td_vla_copy(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void td_vla_display(int rows, int cols, double arr[rows][cols]);

int main(void){
    double arr1[SIZE1][SIZE2];
    double arr2[SIZE1][SIZE2];

    srand(time(NULL)); //генерация сида по времени

    //заполняем массивы
    for(int i = 0; i < SIZE1; i++){
        for(int k = 0; k < SIZE2; k++){
            arr1[i][k] = ((double)rand())/rand();
        }
    }

    for(int i = 0; i < SIZE1; i++){
        for(int k = 0; k < SIZE2; k++){
            arr2[i][k] = ((double)rand())/rand();
        }
    }

    td_vla_display(SIZE1, SIZE2, arr1);
    printf("\n");
    td_vla_display(SIZE1, SIZE2, arr2);
    printf("\n");

    td_vla_copy(SIZE1, SIZE2, arr2, arr1);

    td_vla_display(SIZE1, SIZE2, arr1);
    printf("\n");
    td_vla_display(SIZE1, SIZE2, arr2);
    printf("\n");
}

void td_vla_display(int rows, int cols, double arr[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            printf("%6.2lf", arr[i][k]);
        }
        printf("\n");
    }
}

void td_vla_copy(int rows, int cols, double target[rows][cols], double source[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            *(*(target + i) + k) = *(*(source + i) + k);
        }
    }
}
