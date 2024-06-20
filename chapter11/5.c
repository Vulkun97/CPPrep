/*Design and test a function that searches the string specified by the first function 
parameter for the first occurrence of a character specified by the second function 
parameter. Have the function return a pointer to the character if successful, and a null 
if the character is not found in the string. (This duplicates the way that the library 
strchr() function works.) Test the function in a complete program that uses a loop to 
provide input values for feeding to the function.*/

#include <stdio.h>
#define SIZE 21

char* search(const char*, char);

void read(char*, int);

int main(void){
    char str[SIZE];
    char ch;
    char* ptr = NULL;

    while(1){
        printf("Enter a string (%d characters max):\n", SIZE - 1);
        read(str, SIZE - 1);
        printf("Enter a char to find: \n");
        ch = getchar();
        getchar();

        //printf("%c", ch);
        ptr = search(str, ch);
        //printf("%p", ptr);

        if (ptr == NULL){
            printf("There is no such character in the string!\n");
        }
        else{
            printf("Thirst \'%c\' is in %td position!\n", ch, ptr - str + 1);
        }

        printf("Continue? (n for no): ");
        ch = getchar();
        getchar();

        if(ch == 'n')
            break;
    }
    
    printf("Done");
    return 0;
}

char* search(const char* str, char ch){
    char* ptr = NULL;

    while (*str != ch && *str != '\0')
        str++;

    if (*str == ch)
        ptr = (char*) str;

    return ptr;
}

void read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if(str[i] == '\n')
            break;
    }
    while(getchar() != '\n' && str[i] != '\n')
        continue;
    str[i] = '\0';
}