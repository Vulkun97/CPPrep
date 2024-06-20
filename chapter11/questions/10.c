#include <stdio.h>
#include <string.h>
#define SIZE 41

char * s_gets(char * st, int n);
int mystrlen(const char*);

int main(void){
    char input[SIZE];

    printf("Enter max %d characters: ", SIZE - 1);
    s_gets(input, SIZE);

    printf("Your input: %s\n", input);

    printf("Your input length is: %d", mystrlen(input));

    return 0;
}


char * s_gets(char * st, int n){
    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else //
            while (getchar() != '\n')
                continue;
    }
return ret_val;
}

int mystrlen(const char* str){
    int length = 0;
    while (*str++)
        length++;
    
    return length;
}
 