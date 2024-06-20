/*Write a program that echoes the command-line arguments in reverse word order. That 
is, if the command-line arguments are see you later, the program should print later 
you see.*/

#include <stdio.h>

int main (int argc, char* argv[]){
    for(int i = 1; i < argc; i++){
        printf("%s", argv[argc - i]);
        printf(" ");
    }
}