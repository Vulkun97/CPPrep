#include <stdio.h>
#include <string.h>
#define SIZE 21

char * s_gets(char * st, int n);

int main(void){
    char input[SIZE];

    printf("Enter max %d characters: ", SIZE - 1);
    s_gets(input, SIZE);
    printf("Your input: %s", input);

    return 0;
}


char * s_gets(char * st, int n){
    char * ret_val;
    char * strchr_ptr;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        if (strchr_ptr = strchr(st, '\n'))
            *strchr_ptr = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
return ret_val;
}
 