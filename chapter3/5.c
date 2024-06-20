/*There are approximately 3.156 × 10 7 seconds in a year. Write a program that requests 
your age in years and then displays the equivalent number of seconds.*/

#include <stdio.h>

int main (void){
    float age;
    printf("Enter your age: ");
    scanf("%f", &age);
    printf("Your age in seconds is %f s", age * 3.156e7);

    return 0;
}