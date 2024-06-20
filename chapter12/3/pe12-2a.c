/*Redesign the program described in Programming Exercise 2 so that it uses only automatic 
variables. Have the program offer the same user interface—that is, it should prompt the 
user to enter a mode, and so on. You’ll have to come up with a different set of function 
calls, however. */

#include "pe12-2a.h"
#include <stdio.h>


int set_mode(int new_mode){
    static int mode;
    if (new_mode !=0 && new_mode != 1){
        printf("Incorrect mode, most recent valid mode used!\n");
    } 
    else
        mode = new_mode;

    return mode;
}


void get_info(int mode, double* distance, double* fuel){
        while(1){
            mode ? printf("Enter distance traveled in miles: ") :
            printf("Enter distance traveled in kilometers: ");
            
            if (scanf("%lf", distance) != 1){
                getchar();
                continue;
            }
                
            mode ? printf("Enter fuel consumed in gallons: ") :
            printf("Enter fuel consumed in liters: ");
            
            if (scanf("%lf", fuel) != 1){
                getchar();
                continue;
            }
            break;
        }
}


void show_info(int mode, double distance, double fuel){
    mode ? printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel) :
    printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
}