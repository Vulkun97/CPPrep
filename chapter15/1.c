/*Write a function that converts a binary string to a numeric value. That is, if you have 
 char * pbin = "01001001"; */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 30

unsigned int bin_convert(char*);

unsigned int power_of_two (int);

int main(void){
    char* pbin = "01001001";
    unsigned int dec_value = bin_convert(pbin);

    printf("%u", dec_value);
}

unsigned int bin_convert(char* bin_str){
    char* bin_str1 = bin_str;
    unsigned int return_value = 0;
    int power = 0;


    while (*bin_str1)
        bin_str1++;

    do{
        bin_str1--;
        return_value += (*bin_str1 - '0') * power_of_two(power);
        power++;
    }while(bin_str != bin_str1);

    return return_value;
}

unsigned int power_of_two(int power){
    unsigned int return_value = 1;

    for (int i = 0; i < power; i++)
        return_value *= 2;

    return return_value;
}