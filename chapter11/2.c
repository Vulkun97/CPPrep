/*Modify and test the function in exercise 1 so that it stops after n characters or after the 
first blank, tab, or newline, whichever comes first. (Don’t just use scanf() .) 
*/

#include <stdio.h>

#define SIZE 21

void read(char*, int);

int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    read(str, SIZE - 10);

    printf("Read: %s\n", str);
    return 0;
}

void read(char* str, int size){
    int i;
    for(i = 0; i <= size; i++){
        str[i] = getchar();
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            break;
    }
    while(getchar() != '\n' && str[i] != '\n')
        continue;
    str[i] = '\0';
}