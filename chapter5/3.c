/*Write a program that asks the user to enter the number of days and then converts that 
value to weeks and days. For example, it would convert 18 days to 2 weeks, 4 days. 
Display results in the following format: 
 18 days are 2 weeks, 4 days. 
Use a while loop to allow the user to repeatedly enter day values; terminate the loop 
when the user enters a nonpositive value, such as 0 or -20 . */

#include <stdio.h>
#include <string.h>

int main (void){
    const int D_W = 7;

    int days;
    int days_mod;
    int weeks;
    printf("Enter number of days (enter 0 to quit): ");
    scanf("%d", &days);
    while(days > 0){
        weeks = days / D_W;
        days_mod = days % D_W;
        printf("%d days are %d weeks, %d days.\n", days, weeks, days_mod);
        printf("Enter number of days (enter 0 to quit): ");
        scanf("%d", &days);
    }
    printf("Bye!");
}