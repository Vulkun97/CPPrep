#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MIN 1
#define MAX 10
#define TIMES 1

void intsort(int[], int);

int main(void){
    int numbers_count[MAX - MIN + 1] = {[0] = 0};

    for(int i = 0; i < TIMES; i++){
    srand((unsigned int)time(0) + rand());

    for (int i = 0; i < SIZE; i++){
        numbers_count[rand() % (MAX - MIN + 1)]++;
    }
    printf("Count for each number:\n");
    for (int i = 0; i < MAX - MIN + 1; i++){
        printf("Number %3d: %8d\n", MIN + i, numbers_count[i]);
    }

    for (int i = 0; i < MAX - MIN + 1; i++){
        numbers_count[i] = 0;
    }
    }

    printf("Done");
    return 0;
}