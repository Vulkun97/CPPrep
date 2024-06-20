#include <stdio.h>

int call_count(void);

int main(void){
    char answer = 'y';
    while (answer == 'y'){
        printf("Function was called %d times\n", call_count());
        printf("Call one more time (y for yes)? ");
        answer = getchar();
        getchar();
    }
    printf("Done");
    return 0;
}

int call_count(void){
    static int count;
    return ++count;
}