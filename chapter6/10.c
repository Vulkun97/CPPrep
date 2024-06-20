/*Write a program that requests lower and upper integer limits, calculates the sum of all 
the integer squares from the square of the lower limit to the square of the upper limit, 
and displays the answer. The program should then continue to prompt for limits and 
display answers until the user enters an upper limit that is equal to or less than the lower 
limit. A sample run should look something like this: 
 Enter lower and upper integer limits: 5 9
 The sums of the squares from 25 to 81 is 255
 Enter next set of limits: 3 25
 The sums of the squares from 9 to 625 is 5520
 Enter next set of limits: 5 5
 Done 
*/

#include <stdio.h>

int main (void){
    int sum = 0;
    int upper = 0;
    int lower = 0;

    printf("Enter lower and upper limit as integers: ");
    scanf("%d %d", &lower, &upper);

    while (lower < upper) {
        for (int i = lower; i <= upper; i++)
            sum += i*i;

        printf("The sum of the squares form %d to %d is %d\n",
        lower * lower, upper * upper, sum);

        sum = 0;
        upper = 0;
        lower = 0;
        printf("Enter lower and upper limit as integers: ");
        scanf("%d %d", &lower, &upper);
    }

    printf("Done");

    return 0;
}