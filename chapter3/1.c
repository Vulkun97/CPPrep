/*Find out what your system does with integer overflow, floating-point overflow, and 
floating-point underflow by using the experimental approach; that is, write programs 
having these problems. (You can check the discussion in Chapter 4of limits.h and 
float.h to get guidance on the largest and smallest values.)*/

#include <stdio.h>

int main(void){

    int overflow_int = 1;
    float overflow_float = 1;
    float underflow_float = 1;

    do{
    printf("%d\n", overflow_int *= 2);
    printf("%f\n", overflow_float *= 2);
    printf("%f\n", underflow_float /= 2);

        if (getchar() == 's')
        {
            return 0;
        }
        
    } while (1);

    return 0;
}