/*Write a function that takes as arguments the name of an array of type int elements, the 
size of an array, and a value representing the number of picks. The function then should 
select the indicated number of items at random from the array and prints them. No 
array element is to be picked more than once. (This simulates picking lottery numbers or 
jury members.) Also, if your implementation has time() (discussed in Chapter 12 ) or a 
similar function available, use its output with srand() to 
initialize the rand() random number generator. Write a simple program that tests the function. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 20

void pick(int[], const unsigned int, const unsigned int);

int main(void){
    srand(time(NULL));

    int array[SIZE];
    unsigned int picks;

    printf("Array is:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d\n", array[i] = rand());
    }
        
    printf("Enter number of picks: ");
    scanf("%u", &picks);

    pick(array, SIZE, picks);

    printf("Done!");
    
}

void pick(int array[], const unsigned int size,const unsigned int picks){
    unsigned int index;
    int i = 0;
    
    while (i < picks){
        index = rand() % size;

        if (array[index]) {
            printf("Pick number %d is %d\n", i + 1, array[index]);
            array[index] = 0;
            if (size == i + 1)
                return;
            i++;
        }
    }
}

