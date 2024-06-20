/*Write a function called transform() that takes four arguments: the name of a source 
array containing type double data, the name of a target array of type double, an int
representing the number of array elements, and the name of a function (or, equivalently, 
a pointer to a function). The transform() function should apply the indicated function 
to each element in the source array, placing the return value in the target array. For 
example, the call 
 transform(source, target, 100, sin); 
would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function 
in a program that calls transform() four times, using two functions from the math.h
library and two suitable functions of your own devising as arguments to successive calls 
of the transform() function.
*/

#include <stdio.h>
#include <math.h>

#define SIZE 10

void transform(double*, double*, int, double (*)(double));

double fun1(double);

double fun2(double);

int main(void){
    double target [SIZE];
    double source [SIZE];

    for(int i = 0; i < SIZE; i++){
        source[i] = i*i;
    }

    for(int i = 0; i < SIZE; i++){
        printf("%f\n", source[i]);
    }
    printf("\n");

    transform(target, source, SIZE, sin);

    for(int i = 0; i < SIZE; i++){
        printf("%f\n", target[i]);
    }
    printf("\n");

    transform(target, source, SIZE, cos);

    for(int i = 0; i < SIZE; i++){
        printf("%f\n", target[i]);
    }
    printf("\n");

    transform(target, source, SIZE, fun1);

    for(int i = 0; i < SIZE; i++){
        printf("%f\n", target[i]);
    }
    printf("\n");

    transform(target, source, SIZE, fun2);

    for(int i = 0; i < SIZE; i++){
        printf("%f\n", target[i]);
    }
    printf("\n");
}

void transform(double* target, double* source, int size, double (*fp)(double)){
    for(int i = 0; i < size; i++){
        target[i] = fp(source[i]);
    }
}

double fun1(double x){
    return -x;
}

double fun2(double x){
    return x/10;
}