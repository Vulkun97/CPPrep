/*Rewrite the rain program in Listing 10.7so that the main tasks are performed by 
functions instead of in main() .*/

#include <stdio.h>
#define MONTHS 12 // number of months in a year
#define YEARS 5 // number of years of data

float arr_sum(const float[], int);

void arr_flip(int rows, int cols, float target [rows][cols], const float source [cols][rows]);

int main(void)
{
// initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    float fliped[MONTHS][YEARS];
    int year, month;
    float subtot, total;

    printf(" YEAR RAINFALL (inches)\n");
    //
    for (year = 0, total = 0; year < YEARS; year++)
    {
        subtot = arr_sum(rain[year], MONTHS);
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // total for all years
    }
    //
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf(" Nov Dec\n");
    //
    arr_flip(MONTHS, YEARS, fliped, rain);

    
    for (month = 0; month < MONTHS; month++)
    { // for each month, sum rainfall over years
        subtot = arr_sum(fliped[month], YEARS);
        printf("%4.1f ", subtot/YEARS);
    }
    //
    printf("\n");

    return 0;
    
} 

float arr_sum(const float arr[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

void arr_flip(int rows, int cols, float target [rows][cols], const float source [cols][rows]){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            target[i][k] = source[k][i];
        }
    }
}