/*Write a function that returns the difference between the largest and smallest elements of 
an array-of- double. Test the function in a simple program.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


double difference (double*, int);

int main(void){
    double arr[SIZE];
    double num;

    srand(time(NULL)); //генерация сида по времени

    for(int i = 0; i < SIZE; i++){
        arr[i] = ((double)rand())/rand();
        printf("%5.2lf ", arr[i]);
    }

    printf("\n");

    num = difference(arr, SIZE);

    printf("difference of largest and smallest is %.4lf", num);

    return 0;
}

double difference(double* arr, int size){
    double largest = arr[0];
    double smallest = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }

    return largest - smallest;
}