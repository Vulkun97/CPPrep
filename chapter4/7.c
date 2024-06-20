/*Write a program that sets a type double variable to 1.0/3.0 and a type float variable 
to 1.0/3.0. Display each result three times—once showing four digits to the right of the 
decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits 
to the right of the decimal. Also have the program include float.h and display the 
values of FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these 
values?*/

#include <stdio.h>
#include <string.h>
#include <float.h>

int main (void){
    float f_one_third = 1.0 / 3.0;
    double db_one_third = 1.0 / 3.0;

    printf("%18.4f %18.4f\n"
    "%18.12f %18.12f\n"
    "%18.16f %18.16f\n",
    f_one_third, db_one_third, f_one_third, db_one_third, f_one_third, db_one_third);
    
    
    printf("\n%18d %18d\n", FLT_DIG, DBL_DIG);
    
    return 0;
}