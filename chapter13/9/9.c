/*Modify the program in Listing 13.3 so that each word is numbered according to the order 
in which it was added to the list, starting with 1. Make sure that, when the program is 
run a second time, new word numbering resumes where the previous numbering left off.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int last_word(FILE*);

int main(void){
    FILE *fp;
    char words[MAX];
    char ch;
    int count;

    if ((fp = fopen("wordyi", "a+")) == NULL){
        fprintf(stdout,"Can't open \"wordyi\" file.\n");
        exit(EXIT_FAILURE);
    }

    count = last_word(fp);
    
    puts("Enter words to add to the file; enter EOF at the beginning of a line to terminate.");

    while ((fscanf(stdin,"%40s", words) == 1) && (words[0] != EOF))
        fprintf(fp, "%5d %s\n", ++count, words);

    puts("File contents:");
    rewind(fp); /* go back to beginning of file */

    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
        
    return 0;
}

int last_word(FILE* fp){
    int index;

    fseek(fp, 0, SEEK_END);

    if (ftell(fp) == 0)
        return 0;

    rewind(fp);

    while(fscanf(fp, "%d %*s", &index) != EOF)
        continue;
    
    return index;
}