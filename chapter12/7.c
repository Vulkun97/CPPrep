/*Write a program that behaves like the modification of Listing 12.13 , which we discussed 
after showing the output of Listing 12.13 . That is, have the program produce output like 
the following: 
 Enter the number of sets; enter q to stop : 18 
 How many sides and how many dice? 6 3 
 Here are 18 sets of 3 6-sided throws.
 12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
 13 8 14
 How many sets? Enter q to stop: q*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int roll_n_dice(int dice, int sides);

int roll_count = 0;

int main(void){
    int roll;
    int sets, dices, sides;
    int status;

    srand((unsigned int) time(0)); /* randomize seed */



    printf("Enter the number of sets; enter q to stop.\n");
    while (scanf("%d", &sets) == 1 && sets > 0){
        printf("How many sides and how many dices?\n");
        if (scanf("%d %d", &sides, &dices) != 2 || sides < 2 || dices < 1){
            break;
        }

        printf("Here are %d sets of %d %d-sided throws.\n", sets, dices, sides);

        for(int i = 0; i < sets; i++){
            printf("%4d ", roll_n_dice(dices, sides));
            if ((i + 1) % 10 == 0)
                printf("\n");
        }

        printf("\nEnter the number of sets; enter q to stop.\n");
    }
    
    
    printf("The rollem() function was called %d times.\n",
    roll_count); /* use extern variable */
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}

static int rollem(int sides){
    int roll;
    roll = rand() % sides + 1;
    ++roll_count; /* count function calls */
    return roll;
}

int roll_n_dice(int dice, int sides){
    int d;
    int total = 0;
    if (sides < 2){
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1){
        printf("Need at least 1 die.\n");
        return -1;
    }
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    return total;
}