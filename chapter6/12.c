/*Consider these two infinite series: 
 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... 
Write a program that evaluates running totals of these two series up to some limit of 
number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself 
an even number of times is 1. Have the user enter the limit interactively; let a zero or 
negative value terminate input. Look at the running totals after 100 terms, 1000 terms, 
10,000 terms. Does either series appear to be converging to some value?*/

#include <stdio.h>

int main (void){
    long long int limit = 0;
    double series1 = 0.0;
    double series2 = 0.0;

    printf("Enter limit of terms: ");
    scanf ("%lld", &limit);
    while (limit > 0){
        for (long long int i = 0; i < limit; i ++){
            series1 += 1/(double)(1+i);
            series2 += 1/(double)(1+i) * (1 - 2 * (i%2));
        }
    printf ("Thirst series is %lf\n", series1);
    printf ("Second series is %lf\n", series2); //natural logarithm of two

    series1 = 0.0;
    series2 = 0.0;
    limit = 0;
    printf("Enter limit of terms: ");
    scanf ("%lld", &limit); 
    };

    printf("Done");
    return 0;
}