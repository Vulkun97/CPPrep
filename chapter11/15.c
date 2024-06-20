/*Use the character classification functions to prepare an implementation of atoi(); have 
this version return the value of 0 if the input string is not a pure number.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int power(int, int);

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Arg is not entered");
        return 0;
    }

    int not_int = 0;
    int number = 0;
    int length = strlen(argv[1]) - 1;

    for (int i = 0; i < length + 1; i++){
        if (!isdigit(argv[1][length - i])){
            not_int = 1;
            break;
        }
        number += (argv[1][length - i] - 48) * power(10, i);
    }

    if (not_int)
        printf("Arg is not int");
    else
        printf("Arg in int format: %d", number);

    return 0;
}

int power(int base, int pw){
    int answer = 1;

    for(int i = 0; i < pw; i++){
        answer *= base;
    }

    return answer;
}