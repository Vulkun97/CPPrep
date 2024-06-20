/*Write a program that reads two binary strings as command-line arguments and prints 
the results of applying the ~ operator to each number and the results of applying the 
&, |, and ^ operators to the pair. Show the results as binary strings.*/

#include <string.h>
#include <stdio.h>

char not(char);

char and(char, char);

char or(char, char);

char xor(char,char);

void not_operation(char*);

void bin_operation(char(*)(char, char), char*, char*);

int main (int argc, char* argv[]){

    printf("NOT operation:\n");
    not_operation(argv[1]);
    not_operation(argv[2]);

    printf("AND operation:\n");
    bin_operation(and, argv[1], argv[2]);

    printf("OR operation:\n");
    bin_operation(or, argv[1], argv[2]);

    printf("XOR operation:\n");
    bin_operation(xor, argv[1], argv[2]);
}

char not(char x){
    return (~(x-'0') & 1) + '0';
}

char and(char x, char y){
    return ((x - '0') & (y - '0')) + '0';
}

char or(char x, char y){
    return ((x - '0') | (y - '0')) + '0';
}

char xor(char x, char y){
    return ((x - '0') ^ (y - '0')) + '0';
}


void not_operation(char* bin_str){
    while(*bin_str){
        printf("%c", not(*bin_str));
        bin_str++;
    }
    printf("\n");
}

void bin_operation(char(*fun)(char, char), char* x, char* y){
    while (*x & *y){
        printf("%c", fun(*x, *y));
        x++;
        y++;
    }
    printf("\n");
}