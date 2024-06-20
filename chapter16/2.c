#include "macro.h"
#include <stdio.h>

int main(void){
    double x = 1212;
    double y = 4546;

    printf("harmonic mean is %f", HARMONIC_MEAN(x, y));
}