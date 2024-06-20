/*Modify Listing 16.17 so that it uses an array of struct names elements (as defined after 
the listing) instead of an array of double. Use fewer elements, and initialize the array 
explicitly to a suitable selection of names*/

/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"

#define SIZE 40

struct names {
    char first[SIZE];
    char last[SIZE];
};

int comp_names(const void * p1, const void * p2);

void get_names(struct names *names, int size);

void print_names(struct names *names, int size);

int main(void){
    int entries = 0;

    printf("Enter number of entries: ");
    scanf("%d", &entries);

    struct names names[entries];

    get_names(names, entries);

    qsort(names, entries, sizeof(struct names), comp_names);

    printf("Sorted entries: \n");

    print_names(names, entries);

    return 0;
}

void get_names(struct names *names, int size){
    SKIP
    for (int i = 0; i < size; i++){
        printf("Enter firs name for %d entry:\n", i + 1);
        fgets(names[i].first, SIZE, stdin);

        printf("Enter last name for %d entry:\n", i + 1);
        fgets(names[i].last, SIZE, stdin);
    }
    
}

void print_names(struct names *names, int size){
    for(int i = 0; i < size; i++){
        printf("%d: %s %s\n", i + 1, names[i].first, names[i].last);
    }
}


 /* sort by last name then by first name */
int comp_names(const void * p1, const void * p2){
    /* get right type of pointer */
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last); /* compare last names */
    if (res != 0)
        return res;
    else /* last names identical, so compare first names */
        return strcmp(ps1->first, ps2->first);
}