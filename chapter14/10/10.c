/*Write a program that implements a menu by using an array of pointers to functions. For 
instance, choosing a from the menu would activate the function pointed to by the first 
element of the array.*/

#define SIZE 10

#include <stdio.h>
#include <string.h>

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);
void fun6(void);
void fun7(void);
void fun8(void);
void fun9(void);
void fun10(void);

int main(void){
    int fnum = 2;
    void (*parr[SIZE])(void);

    parr[0] = fun1;
    parr[1] = fun2;
    parr[2] = fun3;
    parr[3] = fun4;
    parr[4] = fun5;
    parr[5] = fun6;
    parr[6] = fun7;
    parr[7] = fun8;
    parr[8] = fun9;
    parr[9] = fun10;

    printf("Enter number of function to invoke: ");
    scanf("%d", &fnum);

    (*parr[fnum-1])(); //два разных способа вызова функции по указателю
    parr[fnum-1]();   

}

void fun1(void){
    printf("I am the function number 1\n");
}

void fun2(void){
    printf("I am the function number 2\n");
}

void fun3(void){
    printf("I am the function number 3\n");
}

void fun4(void){
    printf("I am the function number 4\n");
}

void fun5(void){
    printf("I am the function number 5\n");
}

void fun6(void){
    printf("I am the function number 6\n");
}

void fun7(void){
    printf("I am the function number 7\n");
}

void fun8(void){
    printf("I am the function number 8\n");
}

void fun9(void){
    printf("I am the function number 9\n");
}

void fun10(void){
    printf("I am the function number 10\n");
}