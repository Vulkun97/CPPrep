 /*Modify the get_first() function of Listing 8.8so that it returns the first non-whitespace character encountered. Test it in a simple program.*/

#include <stdio.h>
char get_first(void);

int main (void){
    char ch;
    printf("Some characters: ");
    ch = get_first();
    printf("First non space character is %c", ch);
    return 0;
}


char get_first(void){
    char ch;
    while ((ch = getchar()) == ' ')
        continue;
    return ch;
}
 