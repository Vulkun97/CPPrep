/*Write a function called string_in() that takes two string pointers as arguments. If 
the second string is contained in the first string, have the function return the address 
at which the contained string begins. For instance, string_in("hats", "at") would 
return the address of the a in hats. Otherwise, have the function return the null pointer.*/

#include <stdio.h>
#define SIZE 21

void read(char*, int);

char* string_in(const char*, const char*);

int main(void){
    char str1[SIZE];
    char str2[SIZE];
    char* ptr;

    printf("Enter a string of %d characters max: ", SIZE - 1);
    read(str1, SIZE - 1);

    printf("Enter a string of %d characters max to find in first string: ", SIZE - 1);
    read(str2, SIZE - 1);
    

    ptr = string_in(str1, str2);

    if (ptr == NULL){
            printf("There is no such character in the string!\n");
        }
        else{
            printf("First \'%s\' is in %td position!\n", str2, ptr - str1 + 1);
        }

    return 0;
}

char* string_in(const char* str1, const char* str2){
    char* ptr = NULL;

    int i;
    while(str1 != '\0'){
        for (i = 0; *(str2+i) != '\0' && *(str1+i) != '\0'; i++){
            if(*(str1 + i) != *(str2 + i))
                break;
        }
        if (*(str2+i) == '\0'){
            ptr = (char*) str1;
            break;
        }

        str1++;
    }

    return ptr;
}

void read(char* str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = getchar();
        if(str[i] == '\n')
            break;
    }
    if(i == size)
        while(getchar() != '\n')
            continue;
    
    str[i] = '\0';
}