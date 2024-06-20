/*Write a program that reads input as a stream of characters until encountering EOF. Have 
it report the average number of letters per word. Don’t count whitespace as being letters 
in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that 
now. (If you do want to worry about it, consider using the ispunct() function from the 
ctype.h family.)*/

#include <stdio.h>
#include <ctype.h>
#define MAX 200

int main (void){
    int ch;
    int past_ch = ' ';
    int letters = 0;
    int words = 0;
    int in_word = 0;
    int ch_count = 0;
    int ch_buffer[MAX];

    while (((ch = getchar()) != EOF) && ch_count < MAX){
        if (isalpha(ch) && isspace(past_ch)){
            in_word = 1;
            words++;
        }
        else if (isspace(ch) && isalpha(past_ch))
            in_word = 0;

        if (in_word)
            letters++;

        past_ch = ch;
        ch_count++;
    }
    printf("There was %d letters and %d words\n", letters, words);
    printf("Average number of letters in entered words is %.2f\n", (float)letters / words);


    printf("Done");
    return 0;
}