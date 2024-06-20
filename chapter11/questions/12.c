#include <stdio.h>
#include <string.h>

#define SIZE 21

char * s_gets(char * st, int n);
char* find_space(const char*);

int main(void){
    char str[SIZE];
    char *space = NULL;

    printf("Enter a string of words max %d characters long:\n", SIZE-1);
    s_gets(str, SIZE);

    space = find_space(str);

    if (space)
        printf("Thirst space is %zd character!\n", space - str + 1);

    return 0;
}

char* find_space(const char* str){
    return strchr(str, ' ');
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
 