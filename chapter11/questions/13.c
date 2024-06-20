#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "GRANT"
#define SIZE 40

char * s_gets(char * st, int n);
void str_upper(char[]);

int main(void){
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    str_upper(try);

   

    while (strcmp(try, ANSWER) != 0){
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
        str_upper(try);
    }

    puts("That's right!");
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

void str_upper(char str[]){
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}