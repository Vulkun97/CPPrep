/*Write a program with the following behavior. First, it asks you how many words you 
wish to enter. Then it has you enter the words, and then it displays the words. Use 
malloc() and the answer to the first question (the number of words) to create a dynamic 
array of the corresponding number of pointers-to- char. (Note that because each element 
in the array is a pointer-to- char, the pointer used to store the return value of malloc()
should be a pointer-to-a-pointer-to- char.) When reading the string, the program should 
read the word into a temporary array of char, use malloc() to allocate enough storage 
tohold the word, and store the address in the array of char pointers. Then it should 
copy the word from the temporary array into the allocated storage. Thus, you wind up 
with an array of character pointers, each pointing to an object of the precise size needed 
to store the particular word. A sample run could look like this: 
 How many words do you wish to enter? 5 
 Enter 5 words now:
 I enjoyed doing this exerise 
 Here are your words:
 I
 enjoyed
 doing
 this
 exercise */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

void next_word(char*, int);

int main(void){
    int words;
    char** arr;
    char buffer[SIZE];
    int length;

    printf("How many words do you wish to enter? ");
    scanf("%d", &words);
    getchar();

    arr = (char**)malloc(words * sizeof(char*));

    printf("Enter %d words now:\n", words);

    for(int i = 0; i < words; i++){
        next_word(buffer, SIZE - 1);
        length = strlen(buffer);
        arr[i] = (char*)malloc(length * sizeof(char));
        strcpy(arr[i], buffer);
    }

    printf("Here are your words:\n");
    
    for(int i = 0; i < words; i++){
        printf("%s\n", arr[i]);
    }
    
}

void next_word(char* str, int size){
    char ch;
    int index = 0;
    static int overflow;

    ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\0' || overflow){
        if (ch == ' ' || ch == '\n' || ch == '\0')
            overflow = 0;
        ch = getchar();
    }
        
    while (ch != ' ' && ch != '\n' && ch != '\0' && index < size){
        str[index] = ch;
        ch = getchar();
        index++;
    }

    if (index == size)
        overflow = 1;

    str[index] = '\0';

}