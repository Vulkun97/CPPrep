 /*Programs using command-line arguments rely on the user’s memory of how to use them 
correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line 
arguments, it prompts the user for the required information.*/
 
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>

#define LEN 30

int main(void){
    FILE *in, *out; // declare two FILE pointers
    int ch;
    char name[LEN]; // storage for output filename
    char src_name[LEN];
    int count = 0;

    printf("Enter a file name:\n");
    scanf("%s", src_name);

    // set up input
    if ((in = fopen(src_name, "r")) == NULL){
        fprintf(stderr, "I couldn't open the file \"%s\"\n", src_name);
        exit(EXIT_FAILURE);
    }

    // set up output
    strncpy(name,src_name, LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name,".red"); // append .red

    if ((out = fopen(name, "w")) == NULL){ // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out); // print every 3rd char 

    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    return 0;
}