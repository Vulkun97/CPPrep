/*Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in 
the order entered, then alphabetized by title, and then in order of increased value.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books */

struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);

void print_by_entered(struct book*, int);

void print_by_title(struct book*, int);

void print_by_value(struct book*, int);



int main(void) {
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0'){
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue; /* clear input line */

        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0){
        print_by_entered(library, count);

        print_by_title(library, count);

        print_by_value(library, count);

    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

void print_by_entered(struct book library[], int size){

    printf("Here is the list of your books:\n");

    for (int i = 0; i < size; i++)
        printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
}

void print_by_title(struct book library[], int size){
    struct book buffer;

    for(int i = 0; i < size; i++){
        for(int k = i + 1; k < size; k++)
            if(strcmp(library[i].title, library[k].title) > 0){
                buffer = library[i];
                library[i] = library[k];
                library[k] = buffer;
            }
    }

    printf("Here is the list of your books sorted by title:\n");

    for(int i = 0; i < size; i++){
         printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
    }
}

void print_by_value(struct book library[], int size){
    struct book buffer;

    for(int i = 0; i < size; i++){
        for(int k = i + 1; k < size; k++)
            if(library[i].value > library[k].value){
                buffer = library[i];
                library[i] = library[k];
                library[k] = buffer;
            }
    }

    printf("Here is the list of your books sorted by value:\n");

    for(int i = 0; i < size; i++){
         printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
    }
}


char * s_gets(char * st, int n){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);

    if (ret_val){
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }

    return ret_val;
}

