/*Do Programming Exercise 13, but use variable-length array function parameters. 
*/

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