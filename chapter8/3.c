/*Write a program that reads input as a stream of characters until encountering EOF . 
Have it report the number of uppercase letters, the number of lowercase letters, and the 
number of other characters in the input. You may assume that the numeric values for the 
lowercase letters are sequential and assume the same for uppercase. Or, more portably, 
you can use appropriate classification functions from the ctype.h library. */

#include <stdio.h>
#include <ctype.h>
#define MAX 200

int main (void){
    int upper = 0;
    int lower = 0;
    int other = 0;
    int ch;
    int ch_count = 0;
    int ch_buffer[MAX];

    while (((ch = getchar()) != EOF)){
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
        else
            other++;
    }

    printf("There was %d uppercase letters\n", upper);
    printf("There was %d lowercase letters\n", lower);
    printf("There was %d other characters\n", other);

    return 0;
}