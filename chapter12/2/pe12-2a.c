/*Gasoline consumption commonly is computed in miles per gallon in the U.S. and in 
liters per 100 kilometers in Europe. What follows is part of a program that asks the user 
to choose a mode (metric or U.S.) and then gathers data and computes fuel consumption: 
 
 Here is some sample output: 
 Enter 0 for metric mode, 1 for US mode: 0
 Enter distance traveled in kilometers: 600
 Enter fuel consumed in liters: 78.8
 Fuel consumption is 13.13 liters per 100 km.
 Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
 Enter distance traveled in miles: 434
 Enter fuel consumed in gallons: 12.7
 Fuel consumption is 34.2 miles per gallon.
 Enter 0 for metric mode, 1 for US mode (-1 to quit): 3
 Invalid mode specified. Mode 1(US) used.
 Enter distance traveled in miles: 388
 Enter fuel consumed in gallons: 15.3
 Fuel consumption is 25.4 miles per gallon.
 Enter 0 for metric mode, 1 for US mode (-1 to quit): -1
 Done. 
If the user enters an incorrect mode, the program comments on that and uses the most 
recent mode. Supply a pe12-2a.h header file and a pe12-2a.c source code file to make 
this work. The source code file should define three file-scope, internal-linkage variables. 
One represents the mode, one represents the distance, and one represents the fuel 
consumed. The get_info() function prompts for data according to the mode setting 
and stores the responses in the file-scope variables. The show_info() function calculates 
and displays the fuel consumption based on the mode setting. You can assume the user 
responds with numeric input. */

#include "pe12-2a.h"
#include <stdio.h>

int mode;
double distance;
double fuel;

void set_mode(int new_mode){
    if (new_mode !=0 && new_mode != 1){
        printf("Incorrect mode, most recent valid mode used!\n");
    } 
    else
        mode = new_mode;
}


void get_info(){
        while(1){
            mode ? printf("Enter distance traveled in miles: ") :
            printf("Enter distance traveled in kilometers: ");
            
            if (scanf("%lf", &distance) != 1){
                getchar();
                continue;
            }
                
            mode ? printf("Enter fuel consumed in gallons: ") :
            printf("Enter fuel consumed in liters: ");
            
            if (scanf("%lf", &fuel) != 1){
                getchar();
                continue;
            }
            break;
        }
}


void show_info(){
    mode ? printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel) :
    printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
}