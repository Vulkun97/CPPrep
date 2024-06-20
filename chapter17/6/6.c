/*Write a function that takes three arguments: the name of an array of sorted integers, the 
number of elements of the array, and an integer to seek. The function returns the value 
1 if the integer is in the array, and 0 if it isn’t. Have the function use the binary search 
technique. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

unsigned int seek(const int array[], int size, const int number);

void populate(int array[],const int size);

void printa(const int array[],const int size);

void sort(int array[],const int size);

int comp(const void *x, const void *y);

int numPlaces (int n);

int main(void){
    srand(time(NULL));

    int array[SIZE];
    int number;

    int not_found = 0;

    populate(array, SIZE);

    printf("Populated array:\n");
    printa(array, SIZE);

    sort(array, SIZE);

    printf("Sorted array:\n");
    printa(array, SIZE);

    printf("Press Enter to continue");
    getchar();

    printf("Searching for every element of an array:\n");
    for(int i = 0; i < SIZE; i++){
        if(seek(array, SIZE, array[i])){
            printf("Found %d in index %d\n", array[i], i);
        }
        else{
            not_found = 1;
            printf("Not found %d in index %d\n", array[i], i);
        }

    }

    if(not_found)
        printf("Something was not found!\n");
    else
        printf("Everything is found!\n");

    /*printf("Enter number to find: ");
    scanf("%d", &number);

    if (seek(array, SIZE, number))
        printf("Found!\n");
    else
        printf("Not found\n");*/

    printf("Bye!");

    return 0;
}

void populate(int array[],const int size){
    for(int i = 0; i < size; i++){
        array[i] = rand()%(size*10);
    }
}

void printa(const int array[],const int size){
    for(int i = 0; i < size; i++){
        printf("%*d ", numPlaces(size*10 - 1), array[i]);

        if ((i+1) % 10 == 0) 
            printf("\n");
    }
}

int comp(const void *x, const void *y){
    return *(int*)x - *(int*)y;
}

void sort(int array[],const int size){
    qsort(array, size, sizeof(int), comp);
}

unsigned int seek(const int array[], int size, const int number){
    int index = size/2;
    int step = size/2;
    float stepf = size/2.0;

    do {
        stepf = (stepf + 2.0/3) / 2;
        step = stepf;

        if (array[index] > number ){
            
            index = index - step;
        }
        else if ((array[index] < number )){
            index = index + step;
        }
        else
            return 1;
    } while (step);

    return 0;
}

int numPlaces (int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}
