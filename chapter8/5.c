/*Modify the guessing program of Listing 8.4so that it uses a more intelligent guessing 
strategy. For example, have the program initially guess 50, and have it ask the user 
whether the guess is high, low, or correct. If, say, the guess is low, have the next guess 
be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be 
halfway between 75 and 50, and so on. Using this binary search strategy, the program 
quickly zeros in on the correct answer, at least if the user does not cheat. */

#include <stdio.h>
#define MIN 1
#define MAX 100

int main(void){
    int guess = 50;
    int past_guess = 0;
    int answer;
    int buff;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with an b if number is bigger and with l if number is lower.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((answer = getchar()) != 'y'){
        buff = guess;
        
        if (answer == 'b'){
            guess += ((guess - past_guess) > 0 ? guess - past_guess : past_guess - guess)/2;
        } else if (answer == 'l'){
            guess -= ((guess - past_guess) > 0 ? guess - past_guess : past_guess - guess)/2;
        }

        past_guess = buff - 1;

        //printf("%d ", guess);
        //printf("%d\n", past_guess);

        
        getchar();
        printf("Well, then, is it %d?\n", guess);


    }

    printf("I knew I could do it!\n");
    return 0;
} 