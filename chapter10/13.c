/*Write a program that prompts the user to enter three sets of five double numbers each. 
(You may assume the user responds correctly and doesn’t enter non-numeric data.) The 
program should accomplish all of the following: 
 a. Store the information in a 3×5 array. 
 b. Compute the average of each set of five values. 
 c. Compute the average of all the values. 
 d. Determine the largest value of the 15 values. 
 e. Report the results. 
Each major task should be handled by a separate function using the traditional C 
approach to handling arrays. Accomplish task “b” by using a function that computes 
and returns the average of a one-dimensional array; use a loop to call this function three 
times. The other tasks should take the entire array as an argument, and the functions 
performing tasks “c” and “d” should return the answer to the calling program.*/

#include <stdio.h>
#define SIZE1 3
#define SIZE2 5

void populate (int rows, int cols, double arr[rows][cols]);
double find_average (int size, double[size]);
double find_largest (int rows, int cols, double arr[rows][cols]);

int main(void){
    double arr[SIZE1][SIZE2];
    double average[SIZE1];
    double aver_tot;
    double largest;

    printf("Enter %d sets of %d double numbers each: \n", SIZE1, SIZE2);

    populate(SIZE1, SIZE2, arr);

    for (int i = 0; i < SIZE1; i++){
        average[i] = find_average(SIZE2, arr[i]);
    }

    aver_tot = find_average(SIZE1, average);

    largest = find_largest(SIZE1, SIZE2, arr);

    printf("Average of each set: \n");
    for (int i = 0; i < SIZE1; i++){
        printf("%8d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < SIZE1; i++)
        printf(" %7.2lf", average[i]);
    printf("\n");

    printf("Average of all the values: %.2lf\n", aver_tot);
    printf("The largest value of all the values: %.2lf\n", largest);

    return 0;
}

void populate (int rows, int cols, double arr[rows][cols]){
    for (int i = 0; i < rows * cols; i++){
        scanf("%lf", &arr[i/cols][i%cols]);
    }
}

double find_average (int size, double arr[size]){
    double average = 0;

    for (int i = 0; i < size; i++){
        average += arr[i];
    }

    return average / size;
}

double find_largest (int rows, int cols, double arr[rows][cols]){
    double largest = arr[0][0];

    for (int i = 0; i < rows * cols; i++){
        if (arr[i/cols][i%cols] > largest)
            largest = arr[i/cols][i%cols];
    }

    return largest;
}