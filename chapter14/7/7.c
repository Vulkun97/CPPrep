/*Modify Listing 14.14so that as each record is read from the file and shown to you, you 
are given the chance to delete the record or to modify its contents. If you delete the 
record, use the vacated array position for the next record to be read. To allow changing 
the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and 
you’ll have to pay more attention to positioning the file pointer so that appended records 
don’t overwrite existing records. It’s simplest to make all changes in the data stored in 
program memory and then write the final set of information to the file. One approach to 
keeping track is to add a member to the book structure that indicates whether it is to be 
deleted.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */

struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);

void delete_book(int*, struct book*, int);

void modify_book(struct book*, int);

int main(void){
    struct book library[MAXBKS]; /* array of structures */
    int max_count = 0;
    int count = 0;
    int index;
    FILE * pbooks;

    int size = sizeof (struct book);
    

    if ((pbooks = fopen("book.dat", "a+b")) == NULL){
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks); /* go to start of file */

    while (max_count < MAXBKS && fread(&library[max_count], size, 1, pbooks) == 1 && library[max_count].title[0] != '\0')
        max_count++;

    fclose(pbooks);
    if ((pbooks = fopen("book.dat", "wb")) == NULL){
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks);

    while (count < max_count && library[count].title[0] != '\0'){
        char answer = 0;

        if (count == 0 && answer == 0)
            puts("Current contents of book.dat:");

        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);

        count++;

        //printf("File offset: %d\n", ftell(pbooks));
        printf("Would you like to delete or modify the entry? (d for delete, m for modify, other for no): ");
        answer = getchar();
        while (getchar() != '\n')
            continue;
        if(answer == 'd'){
            delete_book(&count, library, max_count);
        }
        else if (answer == 'm'){
            modify_book(library, count-1);
        }
    }
    
    if (count == MAXBKS){
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0'){
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue; /* clear input line */

        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    

    if (count > 0){
        puts("Here is the list of your books:");

        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title, library[index].author, library[index].value);
            
        fwrite(&library[0], size, count, pbooks);
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}

void delete_book(int* count, struct book* library, int size){
    int count_buffer = *count;
    *count -= 1;

    while (count_buffer < size){
        library[count_buffer - 1] = library[count_buffer];
        count_buffer++;
    }

    library[count_buffer-1].title[0] = '\0';
}

void modify_book(struct book* library, int index){
    struct book buffer;
    
    puts("Please add new book title.");
    if (s_gets(buffer.title, MAXTITL) != NULL)
        strcpy(library[index].title, buffer.title);

    puts("Now enter the author.");
    if (s_gets(buffer.author, MAXAUTL) != NULL)
        strcpy(library[index].author, buffer.author);

    puts("Now enter the value.");
    if (scanf("%f", &buffer.value))
        library[index].value = buffer.value;

    printf("Modyfied entry:\n");
    printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

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